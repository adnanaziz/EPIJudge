import sys

ENABLE_TTY_OUTPUT = False
ENABLE_COLOR_OUTPUT = False


def std_out_clear_line():
    print(end='\r')


def set_output_opts(tty_mode, color_mode):
    global ENABLE_TTY_OUTPUT
    global ENABLE_COLOR_OUTPUT

    ENABLE_TTY_OUTPUT = tty_mode.get_or_default(sys.stdout.isatty())
    ENABLE_COLOR_OUTPUT = color_mode.get_or_default(ENABLE_TTY_OUTPUT)


def use_tty_output():
    return ENABLE_TTY_OUTPUT


def use_color_output():
    return ENABLE_COLOR_OUTPUT


def running_on_win():
    return sys.platform == 'win32'


if sys.platform == 'win32':
    try:
        import ctypes
        from ctypes import LibraryLoader

        windll = LibraryLoader(ctypes.WinDLL)  # mypy: ignore
        from ctypes import wintypes
    except (AttributeError, ImportError):
        ENABLE_COLOR_OUTPUT = False

    else:
        from ctypes import POINTER, Structure, byref

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
            _GetConsoleScreenBufferInfo(stdout_handle, byref(csbi))
            return csbi

        def set_console_text_attribute(attrs):
            return _SetConsoleTextAttribute(stdout_handle, attrs)
