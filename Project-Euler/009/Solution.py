import time
# to know the time taken by our code to arrive at the solution
start = time.time()

def compute():
    for i in range(1,1000):
        for j in range(i,1000):
                k = 1000-i-j
                if i*i + j*j == k*k:      #The pythagoras theorem
                        return (i*j*k)
if __name__ == "__main__":
    print(compute())
print("The time taken is ",time.time()-a)      
