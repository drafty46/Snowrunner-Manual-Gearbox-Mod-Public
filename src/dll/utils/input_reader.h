#pragma once

#include "Windows.h"
#include "Xinput.h"
#include "config/ini_config.hpp"
#include "custom_functions.h"

#include <atomic>
#include <boost/property_tree/ptree_fwd.hpp>
#include <filesystem>
#include <functional>
#include <shared_mutex>
#include <thread>
#include <unordered_map>

#include <boost/describe.hpp>

namespace smgm {

BOOST_DEFINE_ENUM(InputDeviceType, KEYBOARD, JOYSTICK)

BOOST_DEFINE_ENUM(InputAction, SHIFT_1_GEAR, SHIFT_2_GEAR, SHIFT_3_GEAR,
                  SHIFT_4_GEAR, SHIFT_5_GEAR, SHIFT_6_GEAR, SHIFT_7_GEAR,
                  SHIFT_8_GEAR, SHIFT_9_GEAR, SHIFT_10_GEAR, SHIFT_11_GEAR, 
                  SHIFT_12_GEAR, SHIFT_HIGH_GEAR, SHIFT_LOW_GEAR,
                  SHIFT_LOW_PLUS_GEAR, SHIFT_LOW_MINUS_GEAR, SHIFT_NEUTRAL,
                  SHIFT_PREV_AUTO_GEAR, SHIFT_NEXT_AUTO_GEAR,
                  SHIFT_REVERSE_GEAR, CLUTCH, DETACH_FROM_GAME);

class InputReader {
public:
  using FncOnPressed = std::function<void()>;

  struct KeyInfo {
    FncOnPressed onPressed;
    bool bPressed = false;
  };

private:
  std::atomic_bool m_bStop = true;
  std::thread m_readerThread;
  std::shared_mutex m_mtx;
  std::unordered_map<WORD, KeyInfo> m_keysKeyboard, m_keysJoystick;

private:
  void ProcessKeys();

public:
  InputReader();
  ~InputReader();

  void Start();

  void Stop();

  void BindKeyboard(SHORT key, FncOnPressed &&onPressed);

  void BindJoystick(WORD key, FncOnPressed &&onPressed);

  void WaitForThread();

  bool ReadInputConfig(const IniConfig &config);

  void WriteDefaultConfig(IniConfig &config);
};
} // namespace smgm
