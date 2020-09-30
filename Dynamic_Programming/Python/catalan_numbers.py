"""
Catalan numbers are a sequence of natural numbers which satisfy the following
recursive formula:
C(0) = 1  and  C(n+1) = summation(i=0 to n) of C(i)*C(n-i)

Here we will see a naive recursive implementation of calculating catalan numbers
and an optimized solution using dynamic programming and then compare the time
taken by them using timeit library.
"""

from timeit import repeat
from typing import Tuple
from random import randint


def catalan_recursive(n: int) -> int:
    """
    Returns the nth catalan number with exponential time complexity.
    >>> catalan_recursive(5)
    42
    >>> catalan_recursive(10)
    16796
    >>> catalan_recursive(0)
    1
    >>> catalan_recursive(-5)
    1
    >>> catalan_recursive(1.5)
    -1
    """
    if not isinstance(n, int):
        return -1
    if n <= 1:
        return 1
    number = 0
    for i in range(n):
        number += catalan_recursive(i) * catalan_recursive(n - i - 1)
    return number


def catalan_dynamic(n: int) -> int:
    """
    Returns the nth catalan number with polynomial time complexity.
    >>> catalan_dynamic(5)
    42
    >>> catalan_dynamic(10)
    16796
    >>> catalan_dynamic(0)
    1
    >>> catalan_dynamic(-5)
    1
    >>> catalan_dynamic(1.5)
    -1
    """
    if not isinstance(n, int):
        return -1
    if n <= 1:
        return 1
    numbers = [0] * (n + 1)
    numbers[0], numbers[1] = 1, 1

    for i in range(2, n + 1):
        for j in range(i):
            numbers[i] += numbers[j] * numbers[i - j - 1]
    return numbers[-1]


random_values = [randint(1, 7) for i in range(5)]


def compare_functions() -> Tuple[float, float]:
    setup_code = """
from __main__ import random_values, catalan_recursive, catalan_dynamic
"""
    test_code1 = """
for i in random_values:
    catalan_recursive(i)
"""
    test_code2 = """
for i in random_values:
    catalan_dynamic(i)
"""
    time1 = repeat(stmt=test_code1, setup=setup_code, repeat=4, number=5000)
    time2 = repeat(stmt=test_code2, setup=setup_code, repeat=4, number=5000)
    return (min(time1), min(time2))


if __name__ == "__main__":
    from doctest import testmod

    testmod()
    times = compare_functions()
    print(f"The time for naive implementation is {times[0]}.")
    print(f"The time for optimized implementation is {times[1]}.")
