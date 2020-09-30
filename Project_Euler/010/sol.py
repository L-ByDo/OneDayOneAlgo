def sieve(n): 

    sum = 0
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
          
        # If prime[p] is not changed, then it is a prime 
        if (prime[p] == True): 
              
            # Update all multiples of p 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
      
    # sum up all prime numbers 
    for p in range(2, n+1): 
        if prime[p]: 
            sum = sum + p
            
    print(sum)
  
for _ in range(int(input())):
    sieve(int(input())) 
