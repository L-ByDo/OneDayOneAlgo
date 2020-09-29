from math import gcd                                                            
from functools import reduce  
                                                  
for _ in range(int(input())):
    print(reduce(lambda x,y: x*y//gcd(x,y), range(1,int(input())+1))) 
