#the given program is for brick sort/odd even sort
arr=[2,1,3]
for round in (0,len(arr)-1):
	for i in range(0,len(arr)-1,2):
		if(arr[i+1]<arr[i]):
			arr[i+1],arr[i]=arr[i],arr[i+1]
	for i in range(1,len(arr)-1,2):
		if arr[i+1]<arr[i]:
			arr[i+1],arr[i]=arr[i],arr[i+1]
print(arr)
