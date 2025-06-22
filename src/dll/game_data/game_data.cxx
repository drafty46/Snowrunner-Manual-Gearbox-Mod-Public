#include "game_data/game_data.h"

#include "config/ini_config.hpp"
#include "game_data/data_types.h"
#include "utils/format_helpers.h"
#include "utils/hooks.h"
#include "utils/logging.h"

#include <algorithm>

float currentCoef = 1.0f;

extern smgm::IniConfig g_IniConfig;

bool SMGM_HOOK_NAME(ShiftGear)(Vehicle* veh, std::int32_t gear, bool allowShiftGear = false) {
	bool result{};
	if (veh->TruckAction->IsInAutoMode == false || allowShiftGear == true) {
		LOG_DEBUG(fmt::format("[ {} ] Switching gear: {} => {}", FormatPointer(veh),
			veh->TruckAction->Gear_1, gear));

		result = SMGM_CALL_ORIG_FN(ShiftGear, veh, gear);
	}
	return result;
}

std::int32_t SMGM_HOOK_NAME(GetMaxGear)(const Vehicle* veh) {
	return SMGM_CALL_ORIG_FN(GetMaxGear, veh);
}

void SMGM_HOOK_NAME(ShiftToAutoGear)(Vehicle* veh) {

	veh->TruckAction->IsInAutoMode == true;

	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		return;
	}

	if (veh->TruckAction->Gear_1 == (GetMaxGear(veh) + 1)) {
		veh->ShiftToGear(veh->GetMaxGear() - 1, 1.0f, true);
	}
	else if (veh->TruckAction->Gear_1 <= 1) {
		veh->ShiftToGear(1, 1.0f, true);
	}
	SMGM_CALL_ORIG_FN(ShiftToAutoGear, veh);
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

	return SMGM_CALL_ORIG_FN(DisableAutoAndShift, veh, gear);
}

void SMGM_HOOK_NAME(SetPowerCoef)(Vehicle* veh, float coef) {
	if (g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		coef = currentCoef;
	}

	SMGM_CALL_ORIG_FN(SetPowerCoef, veh, coef);
}

void SMGM_HOOK_NAME(SetCurrentVehicle)(combine_TRUCK_CONTROL* truckCtrl,
	Vehicle* veh) {
	SMGM_CALL_ORIG_FN(SetCurrentVehicle, truckCtrl, veh);

	LOG_DEBUG(fmt::format("Current vehicle changed to {}", FormatPointer(veh)));

	if (veh && g_IniConfig.Get<bool>("SMGM.DisableGameShifting")) {
		veh->TruckAction->IsInAutoMode = false;
	}
}
