# THIS WILL [NOT](https://youtu.be/dQw4w9WgXcQ) BE MAINTAINED! 

# NEW PROJECT [HERE!](https://github.com/drafty46/SMT)

## SnowRunner Manual Gearbox Mod

Disables 'auto' gear shifting in favor of manual shifting through custom keybindings for keyboard and gamepad.

## Installation

#### Manual Loading

1. Get the latest release [here](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod-Public/releases/latest)
1. Place files from _ManualLoading_ folder next to _SnowRunner.exe_
1. Start SnowRunner
1. Run _smgm-loader.exe_ to load the mod

#### Automatic Loading
1. Get the latest release [here](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod-Public/releases/latest)
1. Place files from _AutomaticLoading_ folder next to _SnowRunner.exe_
1. Start SnowRunner and the mod will load automatically

## Usage

The mod will generate a config file _smgm++.ini_ upon first start.

By default the mod is configured in immersive mode. Switching between Low/High/Auto/Reverse/Neutral is done via the game ui and Auto permits shifting up/down using **LCtrl** and **LAlt** on keyboard, **DPad Left** and **DPad Right** on controller. ImmersiveMode also supports shifting to specific gears.\
Default keys for detaching and reloading config are F10 and F11 respectively.

**Default smgm++.ini**
```
[KEYBOARD]
SHIFT_1_GEAR=
SHIFT_2_GEAR=
SHIFT_3_GEAR=
SHIFT_4_GEAR=
SHIFT_5_GEAR=
SHIFT_6_GEAR=
SHIFT_7_GEAR=
SHIFT_8_GEAR=
SHIFT_9_GEAR=
SHIFT_10_GEAR=
SHIFT_11_GEAR=
SHIFT_12_GEAR=
SHIFT_HIGH_GEAR=
SHIFT_LOW_GEAR=
SHIFT_LOW_PLUS_GEAR=
SHIFT_LOW_MINUS_GEAR=
SHIFT_NEUTRAL=
SHIFT_PREV_AUTO_GEAR=VK_LCONTROL
SHIFT_NEXT_AUTO_GEAR=VK_LMENU
SHIFT_REVERSE_GEAR=
CLUTCH=VK_LSHIFT
DETACH_FROM_GAME=VK_F10
RELOAD_CONFIG=VK_F11
[JOYSTICK]
SHIFT_1_GEAR=
SHIFT_2_GEAR=
SHIFT_3_GEAR=
SHIFT_4_GEAR=
SHIFT_5_GEAR=
SHIFT_6_GEAR=
SHIFT_7_GEAR=
SHIFT_8_GEAR=
SHIFT_9_GEAR=
SHIFT_10_GEAR=
SHIFT_11_GEAR=
SHIFT_12_GEAR=
SHIFT_HIGH_GEAR=
SHIFT_LOW_GEAR=
SHIFT_LOW_PLUS_GEAR=
SHIFT_LOW_MINUS_GEAR=
SHIFT_NEUTRAL=
SHIFT_PREV_AUTO_GEAR=VK_PAD_DPAD_LEFT
SHIFT_NEXT_AUTO_GEAR=VK_PAD_DPAD_RIGHT
SHIFT_REVERSE_GEAR=
CLUTCH=VK_PAD_LSHOULDER
DETACH_FROM_GAME=
RELOAD_CONFIG=
[SMGM]
DisableGameShifting=false
SkipNeutral=false
RequireClutch=false
ImmersiveMode=true

```

- The keybinds use [VirtualKey](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod-Public/blob/master/ValidKeys.txt) values.
- DisableGameShifting disables in-game shifting to avoid conflicts.
- SkipNeutral skips neutral when using PREV_AUTO_GEAR and NEXT_AUTO_GEAR.
- RequireClutch requires the CLUTCH key to be held while changing gears.
- ImmersiveMode limits changing gears to the AUTO position and the rest is done via in-game shifter.


## Improvements over the original

Detaching keybind can be bound in config\
Skipping neutral when shifting up/down can be disabed in config\
Added binds for up to 12 gears\
Added check that game is active window\
Changed config to use VK_ instead of hex values\
Added option to require clutch\
Added ability to reload config via keybind without re-injecting

## Credit to [Ferrster](https://github.com/Ferrster/Snowrunner-Manual-Gearbox-Mod) for the original code
## Credit to [GoldCobaltRound](https://github.com/GoldCobaltRound/Snowrunner-Manual-Gearbox-Mod) for updating the offsets
## Credit to [YAL-Game-Tools](https://github.com/YAL-Game-Tools/TinyModInjector) for the dinput8.dll injector
