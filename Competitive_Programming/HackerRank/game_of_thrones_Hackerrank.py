#if length of string is even,all characters should occure even times. If its odd,only one should occur odd times to occupy space in middle bcz rest even characters will be in pairs ,making string as palindrome 
from collections import Counter
def gameOfThrones(s):
    add = 0
    for x in Counter(s).values():
        add+ = x%2
    return "NO" if add>1 else "YES"

print(gameOfThrones(input()))