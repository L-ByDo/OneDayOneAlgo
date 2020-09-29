"""
To view problem statement:
https://www.hackerrank.com/rest/contests/master/challenges/the-minion-game/download_pdf?language=English
"""


def minion_game(string):
    stuart , kevin = 0, 0
    string = string.casefold()
    length = len(string)
    for index in range(length):
        word = length - index
        if string[index] in "aeiou":kevin += word
        else: stuart += word
    if   stuart > kevin :print("Stuart",stuart)
    elif stuart < kevin :print("Kevin",kevin)
    else:print("Draw")


if __name__ == '__main__':
    s = input()
    minion_game(s)
