def tripletSum(arr,newArr):
    if(len(arr)>2):
        newArr.append(int(arr[0])+int(arr[1])+int(arr[2]))
        return tripletSum(arr[3:],newArr)
    else:
        return newArr
        

# give space sepered values for list
print("Enter list values")
arr=input().split(" ")
newArr=[]
print("Sum of continuous triplets:")
print(tripletSum(arr,newArr))
