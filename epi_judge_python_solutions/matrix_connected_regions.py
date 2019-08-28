import collections
from typing import List

from test_framework import generic_test


def flip_color(x: int, y: int, image: List[List[bool]]) -> None:

    color = image[x][y]
    q = collections.deque([(x, y)])
    image[x][y] = not image[x][y]  # Flips.
    while q:
        x, y = q.popleft()
        for next_x, next_y in ((x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)):
            if (0 <= next_x < len(image) and 0 <= next_y < len(image[next_x])
                    and image[next_x][next_y] == color):
                # Flips the color.
                image[next_x][next_y] = not image[next_x][next_y]
                q.append((next_x, next_y))


def flip_color_wrapper(x, y, image):
    flip_color(x, y, image)
    return image


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_connected_regions.py',
                                       'painting.tsv', flip_color_wrapper))
