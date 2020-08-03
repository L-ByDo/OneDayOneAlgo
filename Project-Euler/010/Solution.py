import time
# to check the time taken by our code to produce the answer
start=time.time()


seive= 2000001*[True]
p=2
limit=2000000
while p*p<=limit:
    if seive[p]==True:
        for i in range(p*p,limit+1,p):
            seive[i]=False
    p+=1   
answer = sum(i for i in range(2,limit+1) if seive[i])    

print("The sum of all prime numbers below 2 Million is ",answer)
print("The time taken is ",time.time()-start)
