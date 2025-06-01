# SnowRunner Manual Gearbox Mod

Disables 'auto' gear shifting in favor of manual shifting through custom keybindings for keyboard and gamepad.

## Installation

#### Manual Loading

1. Get the latest release [here](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod-Public/releases)
1. Place files from _ManualLoading_ folder next to _SnowRunner.exe_
1. Start SnowRunner
1. Run _smgm-loader.exe_ to load the mod

#### Automatic Loading
1. Get the latest release [here](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod-Public/releases)
1. Place files from _AutomaticLoading_ folder next to _SnowRunner.exe_
1. Start SnowRunner and the mod will load automatically

## Usage

When you use the mod for the first time, it'll create a config file _(smgm++.ini)_ near game's main _.exe_ file.\
There you can change keybindings for keyboard and for gamepad separately. By default, cycling through gears is done by **LCtrl** and **LAlt** on keyboard, and **DPad Left & Right** on gamepad. Keys are represented by [VK_](https://github.com/drafty46/Snowrunner-Manual-Gearbox-Mod/blob/master/src/dll/utils/keymap.cxx) values.

## Improvements

Detaching can be bound in config\
Skipping neutral when shifting up/down can be disabed in config\
Added binds for up to 12 gears\
Added check that game is active window\
Changed config to use VK_ instead of hex values\
Added option to require clutch

## Credit to [Ferrster](https://github.com/Ferrster/Snowrunner-Manual-Gearbox-Mod) for the original code
## Credit to [GoldCobaltRound](https://github.com/GoldCobaltRound/Snowrunner-Manual-Gearbox-Mod) for updating the offsets
## Credit to [YAL-Game-Tools](https://github.com/YAL-Game-Tools/TinyModInjector) for the dinput8.dll injector