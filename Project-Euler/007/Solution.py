import time 
#To check the time taken by our code to arrive at solution
import math

start = time.time()

def prime(n):     # returns True if n is prime, False otherwise
    if n%2==0:    #if n is even return False
        return False
    for i in range(3,int(math.sqrt(n)+1),2):
         if n%i==0:
              return False  
    return True  

primes=[2,3,5,7,11,13]
i = 14
while len(primes)!=10001:
    if prime(i):
        primes.append(i)
    i+=1    
        
print("The 10001st prime number is ",primes[10000])
print("The time taken is ",time.time()- start)
