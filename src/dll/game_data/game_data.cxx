#include "game_data/game_data.h"

#include "config/ini_config.hpp"
#include "game_data/data_types.h"
#include "utils/format_helpers.h"
#include "utils/hooks.h"
#include "utils/logging.h"

#include <algorithm>

#include <iostream>

float currentCoef = 1.0f;

std::unordered_map <Vehicle*, std::atomic<bool>> IsInAuto{};

extern smgm::IniConfig g_IniConfig;

bool SMGM_HOOK_NAME(ShiftGear)(Vehicle* veh, std::int32_t gear) {
	LOG_DEBUG(fmt::format("[ {} ] Switching gear: {} => {}", FormatPointer(veh),
		veh->TruckAction->Gear_1, gear));

	return SMGM_CALL_ORIG_FN(ShiftGear, veh, gear);
}

std::int32_t SMGM_HOOK_NAME(GetMaxGear)(const Vehicle* veh) {
	return SMGM_CALL_ORIG_FN(GetMaxGear, veh);
}

void SMGM_HOOK_NAME(ShiftToAutoGear)(Vehicle* veh) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return;
	}

	IsInAuto[veh] = true;
	veh->TruckAction->IsInAutoMode = false;

	if (veh->TruckAction->Gear_1 == (GetMaxGear(veh) + 1)) {
		veh->ShiftToGear(veh->GetMaxGear() - 1, 1.0f);
	}
	else if (veh->TruckAction->Gear_1 <= 1) {
		veh->ShiftToGear(1, 1.0f);
	}
	if (!g_IniConfig.Get<bool>("SMGM.RequireClutch") && !g_IniConfig.Get<bool>("SMGM.ImmersiveMode")) {
		SMGM_CALL_ORIG_FN(ShiftToAutoGear, veh);
	}
}

bool SMGM_HOOK_NAME(ShiftToReverse)(Vehicle* veh) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return false;
	}

	return SMGM_CALL_ORIG_FN(ShiftToReverse, veh);
}

bool SMGM_HOOK_NAME(ShiftToNeutral)(Vehicle* veh) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return false;
	}

	return SMGM_CALL_ORIG_FN(::ShiftToNeutral, veh);
}

bool SMGM_HOOK_NAME(ShiftToHigh)(Vehicle* veh) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return false;
	}

	return SMGM_CALL_ORIG_FN(::ShiftToHigh, veh);
}

bool SMGM_HOOK_NAME(DisableAutoAndShift)(Vehicle* veh, std::int32_t gear) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return false;
	}

	bool result = SMGM_CALL_ORIG_FN(DisableAutoAndShift, veh, gear);
	IsInAuto[veh] = false;
	return result;
}

void SMGM_HOOK_NAME(SetPowerCoef)(Vehicle* veh, float coef) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		coef = currentCoef;
	}
	if (IsInAuto[veh] && (veh->TruckAction->Gear_1 == 1 || veh->TruckAction->Gear_2 == 1)) {
		coef = 1.01;
	}
	SMGM_CALL_ORIG_FN(SetPowerCoef, veh, coef);
	SMGM_CALL_ORIG_FN(ShiftGear, veh, veh->TruckAction->Gear_2);
}

void SMGM_HOOK_NAME(SetCurrentVehicle)(combine_TRUCK_CONTROL* truckCtrl,
	Vehicle* veh) {
	SMGM_CALL_ORIG_FN(SetCurrentVehicle, truckCtrl, veh);

	LOG_DEBUG(fmt::format("Current vehicle changed to {}", FormatPointer(veh)));

	if (veh) {
		IsInAuto[veh] = veh->TruckAction->IsInAutoMode;
		if (IsInAuto[veh]) {
			veh->ShiftToGear(1);
		}
		veh->TruckAction->IsInAutoMode = false;
	}
}
