palindromes = []  # A list to store all palndromes
for num1 in range(100, 1000):  # starting num 1 from 100
    for num2 in range(100000//num1, 1000):  # skipping unnecesarry iteration for num2
        palindrome = num1 * num2
        if str(palindrome) == str(palindrome)[::-1] and palindrome not in palindromes:  # if the number is palindrome and not in list => append
            palindromes.append(palindrome)
palindromes.sort()    # sort the list
length = len(palindromes)

for _ in range(int(input())):
    test = int(input())
    for num in range(length - 1, -1, -1):
        if palindromes[num] < test:
            print(palindromes[num])
            break