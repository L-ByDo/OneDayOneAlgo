#To print all prime numbers from [2,n] for given n in the most efficient seive of eratosthenes algo
import math

def SeiveOfEratosthenes(Num):
    prime = [True for num in range(0, Num+1)] #Set all values from 2 to n as True
    prime[1] = prime[0] = False
    num = 2 

    #Check for square of num if it is less than the root of Num. This is seive till root approach.
    #
    while  num*num <= int(math.sqrt(Num)) :
        if prime[num]:
            for i in range(num*num, Num+1, num):
                prime[i] = False
        num += 1
    count = 0
    for i in range(Num+1):
        if prime[i]:
            count += 1
            print(i)
    return count

if __name__=='__main__':
    Num = int(input())
    count = SeiveOfEratosthenes(Num)
    print(count)
