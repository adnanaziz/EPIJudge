// @library
#pragma once

/**
 * This file defines platform-interfaces to several platform-specific
 * function.
 */

#ifdef _WINDOWS
#include <io.h>
#include <sys/stat.h>
#include <sys/types.h>  //must precede sys/stat.h
#include <cstdio>
#else  // UNIX
#include <sys/stat.h>
#include <unistd.h>
#endif

#include "tribool.h"

namespace platform {

bool ENABLE_TTY_OUTPUT = false;
bool ENABLE_COLOR_OUTPUT = false;

int StdOutFd() {
#ifdef _WINDOWS
  return _fileno(stdout);
#else
  return STDOUT_FILENO;
#endif
}

int IsATty(int fd) {
#ifdef _WINDOWS
  return _isatty(fd);
#else
  return isatty(fd);
#endif
}

void SetOutputOpts(TriBool tty_mode, TriBool color_mode) {
  ENABLE_TTY_OUTPUT =
      GetTriBoolOrDefault(tty_mode, static_cast<bool>(IsATty(StdOutFd())));
  ENABLE_COLOR_OUTPUT = GetTriBoolOrDefault(color_mode, ENABLE_TTY_OUTPUT);
}

bool UseTtyOutput() { return ENABLE_TTY_OUTPUT; }

bool UseColorOutput() { return ENABLE_COLOR_OUTPUT; }

bool IsDir(const char* path) {
#ifdef _WINDOWS
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
#ifdef _WINDOWS
  return '\\';
#else
  return '/';
#endif
}

}  // namespace platform
