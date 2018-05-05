
#pragma once

/**
 * This file defines platform-interfaces to several platform-specific
 * function.
 */

#if _WINDOWS || __MINGW32__ || __CYGWIN__
#define PLATFORM_WIN
#endif

#include <iostream>

#ifdef PLATFORM_WIN
#include <io.h>
#include <sys/stat.h>
#include <sys/types.h>  //must precede sys/stat.h
#include <cstdio>
#else  // UNIX
#include <sys/stat.h>
#include <unistd.h>
#endif

#include "tri_bool.h"

namespace platform {

bool ENABLE_TTY_OUTPUT = false;
bool ENABLE_COLOR_OUTPUT = false;

int StdOutFd() {
#ifdef PLATFORM_WIN
  return _fileno(stdout);
#else
  return STDOUT_FILENO;
#endif
}

int IsATty(int fd) {
#ifdef PLATFORM_WIN
  return _isatty(fd);
#else
  return isatty(fd);
#endif
}

void StdOutClearLine() { std::cout << '\r'; }

void SetOutputOpts(TriBool tty_mode, TriBool color_mode) {
  ENABLE_TTY_OUTPUT =
      GetTriBoolOrDefault(tty_mode, static_cast<bool>(IsATty(StdOutFd())));
  ENABLE_COLOR_OUTPUT = GetTriBoolOrDefault(color_mode, ENABLE_TTY_OUTPUT);
}

bool UseTtyOutput() { return ENABLE_TTY_OUTPUT; }

bool UseColorOutput() { return ENABLE_COLOR_OUTPUT; }

bool IsDir(const char* path) {
#ifdef PLATFORM_WIN
  struct _stat buf {};
  _stat(path, &buf);
  return (buf.st_mode & S_IFDIR) == S_IFDIR;
#else
  struct stat buf {};
  stat(path, &buf);
  return S_ISDIR(buf.st_mode);
#endif
}

char PathSep() {
#ifdef PLATFORM_WIN
  return '\\';
#else
  return '/';
#endif
}

}  // namespace platform
