for _ in range(int(input())):      # looping for number of test cases
    num = int(input())
    fact = 2                       # supposing two as the smallest factorial
    is_prime = 2                   # Taking two as the smallest prime
    while fact * fact <= num :     # Factor is always <= the sqrt of that number
        while num  % fact == 0:    
            is_prime = fact
            num  //= fact    
        fact += 1                  # Incrementing the factorial by 1
    if num > is_prime:             # If the number is itself prime           
        is_prime = num 
    print(is_prime)
