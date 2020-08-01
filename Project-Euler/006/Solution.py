
import time
#importing the time module to check the time taken by our code to arrive at solution

start = time.time()

sum_of_squares = sum(num*num for num in range(1,101))
square_of_sum =  sum(num for num in range(1,101))**2

print(square_of_sum - sum_of_squares)
print("Time taken = ", time.time() - start)
