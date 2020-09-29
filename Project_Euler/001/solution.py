for _ in range(int(input())):   
    n =int(input())
    n -= 1                    #excluding outer-limit
    a= n//3                   
    b= n//5
    c= n//15 
    print((3*a*(a+1) + 5*b*(b+1) - 15*c*(c+1))>>1) #bitwise right-shift