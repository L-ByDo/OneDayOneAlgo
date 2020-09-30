"""
We are given two strings of different lengths and are required to find the
longest common substring
"""
"""
A naive approach to solve this is to consider all substrings of a string and check if
that is present in the second string while keeping track of the maximum length of the
substring.
This approach will take O(m*n^2), where m and n are lengths of the two strings.

However, an efficient approach is to use the technique of dynamic programming.
The idea here is to find the longest common suffix for all substrigs of the two
and store these lengths in a table.
Let's see the implementaton of this.
"""


def lcs(X: str, Y: str, m: int, n: int) -> str:
    """
    Returns the longest common subtring in X and Y
    >>> lcs('ancsfg', 'sfac', 6, 4)
    'The longest common substring is sf'
    >>> lcs('zxcvbn', 'qwerthj', 6, 7)
    'There is no common substring in zxcvbn and qwerthj'
    >>> lcs('adgjk', 'jkfhda', 5, 6)
    'The longest common substring is jk'
    """
    lengths = [[0 for j in range(n + 1)] for i in range(m + 1)]
    max_length = 0
    row, col = 0, 0

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                lengths[i][j] = lengths[i - 1][j - 1] + 1
                if max_length < lengths[i][j]:
                    max_length = lengths[i][j]
                    row, col = i, j
            else:
                lengths[i][j] = 0
    if max_length == 0:
        return f"There is no common substring in {X} and {Y}"
    common_str = ""
    while lengths[row][col] != 0:
        common_str += X[row - 1]
        row -= 1
        col -= 1
    return f"The longest common substring is {common_str[::-1]}"


if __name__ == "__main__":
    from doctest import testmod

    testmod()
    X = input("Enter first string: ")
    Y = input("Enter second string: ")
    m = len(X)
    n = len(Y)
    print(lcs(X, Y, m, n))
