from test_framework.test_utils import enable_timer_hook


# Assume s is a string encoded as bytearray.
def reverse_words(s):
    # Implement this placeholder.
    return


@enable_timer_hook
def reverse_words_wrapper(timer, s):
    output = bytearray()
    output.extend(map(ord, s))

    timer.start()
    reverse_words(output)
    timer.stop()

    return output.decode("utf-8")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('reverse_words.tsv',
                                              reverse_words_wrapper)
