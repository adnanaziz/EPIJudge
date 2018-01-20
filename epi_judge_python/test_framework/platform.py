# @library
import sys

ENABLE_COLOR_OUTPUT = True


def running_on_win():
    return sys.platform == 'win32'


def use_tty_output():
    if not use_tty_output.__dict__.get('cached', None):
        use_tty_output.cached = sys.stdout.isatty()
    return use_tty_output.cached


def use_color_output():
    return use_tty_output() and ENABLE_COLOR_OUTPUT


if running_on_win():
    try:
        import ctypes
        from ctypes import LibraryLoader

        windll = LibraryLoader(ctypes.WinDLL)
        from ctypes import wintypes
    except (AttributeError, ImportError):
        ENABLE_COLOR_OUTPUT = False

    else:
        from ctypes import byref, Structure, c_char, POINTER

        COORD = wintypes._COORD

        class ConsoleScreenBufferInfo(Structure):
            """struct in wincon.h."""
            _fields_ = [
                ("dwSize", COORD),
                ("dwCursorPosition", COORD),
                ("wAttributes", wintypes.WORD),
                ("srWindow", wintypes.SMALL_RECT),
                ("dwMaximumWindowSize", COORD),
            ]


        _GetStdHandle = windll.kernel32.GetStdHandle
        _GetStdHandle.argtypes = [
            wintypes.DWORD,
        ]
        _GetStdHandle.restype = wintypes.HANDLE

        _GetConsoleScreenBufferInfo = windll.kernel32.GetConsoleScreenBufferInfo
        _GetConsoleScreenBufferInfo.argtypes = [
            wintypes.HANDLE,
            POINTER(ConsoleScreenBufferInfo),
        ]
        _GetConsoleScreenBufferInfo.restype = wintypes.BOOL

        _SetConsoleTextAttribute = windll.kernel32.SetConsoleTextAttribute
        _SetConsoleTextAttribute.argtypes = [
            wintypes.HANDLE,
            wintypes.WORD,
        ]
        _SetConsoleTextAttribute.restype = wintypes.BOOL

        STDOUT = -11
        stdout_handle = _GetStdHandle(STDOUT)

        def get_console_screen_buffer_info():
            csbi = ConsoleScreenBufferInfo()
            success = _GetConsoleScreenBufferInfo(stdout_handle, byref(csbi))
            return csbi

        def set_console_text_attribute(attrs):
            return _SetConsoleTextAttribute(stdout_handle, attrs)

