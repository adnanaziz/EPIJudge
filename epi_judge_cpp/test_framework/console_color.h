
#pragma once

#include <functional>
#include <iostream>

#ifdef PLATFORM_WIN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#endif

#include "platform.h"

namespace console_color {

enum class ConsoleColor { FG_RED, FG_GREEN, FG_BLUE, FG_YELLOW, FG_DEFAULT };

short GetColorCodeWin(ConsoleColor color) {
  switch (color) {
    case ConsoleColor::FG_RED:
      return 4 | 8;
    case ConsoleColor::FG_GREEN:
      return 2 | 8;
    case ConsoleColor::FG_BLUE:
      return 1 | 8;
    case ConsoleColor::FG_YELLOW:
      return 6 | 8;
    case ConsoleColor::FG_DEFAULT:
    default:
      return 7;
  }
}

const char* GetColorCodeUnix(ConsoleColor color) {
  switch (color) {
    case ConsoleColor::FG_RED:
      return "\033[31m";
    case ConsoleColor::FG_GREEN:
      return "\033[32m";
    case ConsoleColor::FG_BLUE:
      return "\033[34m";
    case ConsoleColor::FG_YELLOW:
      return "\033[33m";
    case ConsoleColor::FG_DEFAULT:
    default:
      return "\033[39m";
  }
}

template <typename T>
void PrintStdOutColored(ConsoleColor color, const T& value) {
  if (!platform::UseColorOutput()) {
    std::cout << value;
    return;
  }
#ifdef PLATFORM_WIN
  const HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO buffer_info;
  GetConsoleScreenBufferInfo(stdout_handle, &buffer_info);
  const WORD old_text_attr = buffer_info.wAttributes;

  fflush(stdout);
  SetConsoleTextAttribute(stdout_handle, GetColorCodeWin(color));

  std::cout << value;

  fflush(stdout);
  SetConsoleTextAttribute(stdout_handle, old_text_attr);
#else
  std::cout << GetColorCodeUnix(color) << value
            << GetColorCodeUnix(ConsoleColor::FG_DEFAULT);
#endif
}

}  // namespace console_color
