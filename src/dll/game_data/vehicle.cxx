#include "config/ini_config.hpp"
#include "game_data/data_types.h"
#include "game_data/game_data.h"
#include "utils/hooks.h"

#include <algorithm>

#include <iostream>

extern smgm::IniConfig g_IniConfig;

extern std::unordered_map<Vehicle*, std::atomic<bool>> IsInAuto;

extern std::atomic<bool> isRangePressedKb;
extern std::atomic<bool> isRangePressedJoy;

void Vehicle::SetPowerCoef(float coef) { SMGM_CALL_HOOK(SetPowerCoef, this, coef); }

std::int32_t Vehicle::GetMaxGear() const {
	return SMGM_CALL_HOOK(GetMaxGear, this);
}

bool Vehicle::ShiftToGear(std::int32_t targetGear, float powerCoef) {
	std::int32_t gear = std::clamp(targetGear, -1, GetMaxGear() + 1);

	if (g_IniConfig.Get<bool>("SMGM.ImmersiveMode")) {
		if (IsInAuto[this] == false) {
			return true;
		}
		gear = std::clamp(targetGear, 1, GetMaxGear());
	}

	if ((isRangePressedKb || isRangePressedJoy) && gear != (GetMaxGear() + 1)) {
		gear += 6;
		gear = std::clamp(gear, 1, GetMaxGear());
	}

	bool bSwitched = SMGM_CALL_HOOK(ShiftGear, this, gear);

	if (bSwitched) {
		SetPowerCoef(powerCoef);
	}

	return bSwitched;
}

bool Vehicle::ShiftToNextGear() {
	std::int32_t gear = TruckAction->Gear_1 + 1;

	// Skip Neutral
	if (gear == 0 && g_IniConfig.Get<bool>("SMGM.SkipNeutral")) {
		gear = 1;
	}

	return ShiftToGear(std::min(gear, GetMaxGear()));
}

bool Vehicle::ShiftToPrevGear() {
	auto gear = static_cast<std::int32_t>(TruckAction->Gear_1) - 1;

	// Skip Neutral
	if (gear == 0 && g_IniConfig.Get<bool>("SMGM.SkipNeutral")) {
		gear = -1;
	}

	if (g_IniConfig.Get<bool>("SMGM.ImmersiveMode")) {
		gear = std::max(gear, 1);
	}

	return ShiftToGear(std::max(gear, -1));
}

bool Vehicle::ShiftToHighGear() {
	return ShiftToGear(GetMaxGear() + 1);
}

bool Vehicle::ShiftToReverseGear() {
	return ShiftToGear(-1);
}

bool Vehicle::ShiftToLowGear() {
	return ShiftToGear(1, GameRelatedData::PowerCoefLowGear);
}

bool Vehicle::ShiftToLowPlusGear() {
	return ShiftToGear(1, GameRelatedData::PowerCoefLowPlusGear);
}

bool Vehicle::ShiftToLowMinusGear() {
	return ShiftToGear(1, GameRelatedData::PowerCoefLowMinusGear);
}
