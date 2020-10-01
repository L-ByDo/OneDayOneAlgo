# Problem Statement
"""
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
The objective of the puzzle is to move the entire stack to another rod,
obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks
and placing it on top of another stack i.e. a disk can only be moved
if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
"""
from typing import Union


def tower_of_hanoi(
    n: int, from_tower: str, to_tower: str, aux_tower: str
) -> Union[str, int]:
    """
    This recursive function returns each step of shuffling the discs.
    :param n: Number of discs placed in {from_tower}
    :param from_tower: Tower in which discs are initially placed.
    :param to_tower: Tower in which discs are to be placed.
    :param aux_tower: Remaining tower

    >>> tower_of_hanoi(3, A, B, C)
    Traceback (most recent call last):
        ...
    NameError: name 'A' is not defined

    >>> tower_of_hanoi(4, A, B, C)
    Traceback (most recent call last):
        ...
    NameError: name 'A' is not defined

    >>> tower_of_hanoi(4, A, C, B)
    Traceback (most recent call last):
        ...
    NameError: name 'A' is not defined
    """
    if n == 1:
        print("Move disc 1 from Tower {} to Tower {}".format(from_tower, to_tower))
        return
    tower_of_hanoi(n - 1, from_tower, aux_tower, to_tower)
    print("Move disc {} from Tower {} to Tower {}".format(n, from_tower, to_tower))
    tower_of_hanoi(n - 1, aux_tower, to_tower, from_tower)


if __name__ == "__main__":

    # doctest
    import doctest

    doctest.testmod()

    # get_inputs
    num_Discs = int(input("Number of discs "))
    from_Tower, to_Tower, aux_Tower = [
        x for x in input("Input tower name (A/B/C) separated by space.").split()
    ]
    # Function Call
    tower_of_hanoi(num_Discs, from_Tower, to_Tower, aux_Tower)
