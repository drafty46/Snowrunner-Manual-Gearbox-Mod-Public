#include "utils/hooks.h"

#include "game_data/game_data.h"

namespace smgm {
	void AttachHooks() {
#ifdef SMGM_USE_DETOURS
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
#endif

		SMGM_ATTACH_HOOK(ShiftGear);
		SMGM_ATTACH_HOOK(GetMaxGear);
		SMGM_ATTACH_HOOK(ShiftToAutoGear);
		SMGM_ATTACH_HOOK(ShiftToReverse);
		SMGM_ATTACH_HOOK(ShiftToNeutral);
		SMGM_ATTACH_HOOK(ShiftToHigh);
		SMGM_ATTACH_HOOK(DisableAutoAndShift);
		SMGM_ATTACH_HOOK(SetPowerCoef);
		SMGM_ATTACH_HOOK(SetCurrentVehicle);

#ifdef SMGM_USE_DETOURS
		DetourTransactionCommit();
#endif
	}

	void DetachHooks() {
#ifdef SMGM_USE_DETOURS
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
#endif

		SMGM_DETACH_HOOK(ShiftGear);
		SMGM_DETACH_HOOK(GetMaxGear);
		SMGM_DETACH_HOOK(ShiftToAutoGear);
		SMGM_DETACH_HOOK(ShiftToReverse);
		SMGM_DETACH_HOOK(ShiftToNeutral);
		SMGM_DETACH_HOOK(ShiftToHigh);
		SMGM_DETACH_HOOK(DisableAutoAndShift);
		SMGM_DETACH_HOOK(SetPowerCoef);
		SMGM_DETACH_HOOK(SetCurrentVehicle);

#ifdef SMGM_USE_DETOURS
		DetourTransactionCommit();
#endif
	}
} // namespace smgm
