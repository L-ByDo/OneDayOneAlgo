'''
if there is a triplet in array whose sum is equal to the given value print the triplet and return true
the sum is stored in sum variable
''' 
 

def triplet_sum(A, arr_size, sum): 

	# fix one number as i 
	for i in range( 0, arr_size-2): 

		# Fix second number as j
		for j in range(i + 1, arr_size-1): 
			
			# Looking for the third number
			for k in range(j + 1, arr_size): 
				if A[i] + A[j] + A[k] == sum: 
					print("Triplet is", A[i], 
						", ", A[j], ", ", A[k]) 
					return True
	
	# If we reach here, then there is no triplet in the list
	return False
A = [1, 4, 45, 6, 10, 8] 
sum = 22
arr_size = len(A) 
triplet_sum(A, arr_size, sum) 

