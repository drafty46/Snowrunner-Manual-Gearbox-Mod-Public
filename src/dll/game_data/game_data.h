#pragma once

#include "Windows.h"

#include <cstdint>
#include <memory>

#include <fmt/core.h>
#include <libloaderapi.h>
#include <minwindef.h>

#include "game_data/data_types.h"
#include "utils/hooks.h"
#include "utils/memory.h"

namespace GameRelatedData {
	inline const float PowerCoefLowGear = .45f;
	inline const float PowerCoefLowPlusGear = 1.f;
	inline const float PowerCoefLowMinusGear = .2f;

	SMGM_DECLARE_PTR(0x2A4EF58, combine_TRUCK_CONTROL*, TruckControlPtr);
} // namespace GameRelatedData

// SMGM_GAME_FUNCTION(0xD5D0B0, void, SwitchAWD, Vehicle *, bool);
SMGM_GAME_FUNCTION_EXTENDED(0xD56B40, bool, ShiftGear, (Vehicle*, std::int32_t), (Vehicle*, std::int32_t, bool));
SMGM_GAME_FUNCTION(0xD568A0, std::int32_t, GetMaxGear, const Vehicle*);
SMGM_GAME_FUNCTION(0xD568F0, void, ShiftToAutoGear, Vehicle*);
SMGM_GAME_FUNCTION(0xB5DF30, bool, ShiftToReverse, Vehicle*);
SMGM_GAME_FUNCTION(0xB5DC70, bool, ShiftToNeutral, Vehicle*);
SMGM_GAME_FUNCTION(0xB5DB50, bool, ShiftToHigh, Vehicle*);
SMGM_GAME_FUNCTION(0xD5A5F0, bool, DisableAutoAndShift, Vehicle*,
	std::int32_t);
SMGM_GAME_FUNCTION(0xD55CE0, void, SetPowerCoef, Vehicle*, float);
SMGM_GAME_FUNCTION(0xACBB30, void, SetCurrentVehicle, combine_TRUCK_CONTROL*,
	Vehicle*);
