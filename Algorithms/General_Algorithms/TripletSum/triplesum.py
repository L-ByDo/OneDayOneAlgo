def find3Numbers(A, arr_size, sum):  
    A.sort() 
    for i in range(0, arr_size-2):  
        l = i + 1  
        r = arr_size-1 
        while (l < r): 
          
            if( A[i] + A[l] + A[r] == sum): 
                print("Triplet is", A[i],  
                     ', ', A[l], ', ', A[r]); 
                return True
              
            elif (A[i] + A[l] + A[r] < sum): 
                l += 1
            else: # A[i] + A[l] + A[r] > sum 
                r -= 1
    return False
  
A = [1, 4, 45, 6, 10, 8] 
sum = 22
arr_size = len(A) 
  
find3Numbers(A, arr_size, sum) 