"""

For Details of problem statement visit:

https://www.hackerrank.com/rest/contests/master/challenges/alphabet-rangoli/download_pdf?language=English

"""
import string


def print_rangoli(size):
    width = 4*size - 3
    pattern = []
    for i in range(n):
        line = "-".join(string.ascii_lowercase[i:n])
        pattern.append((line[::-1]+line[1:]).center(width, "-"))
    print('\n'.join(pattern[:0:-1]+pattern))


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
