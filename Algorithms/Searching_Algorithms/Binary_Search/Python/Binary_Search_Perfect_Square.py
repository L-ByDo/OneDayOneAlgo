# Find the square of a given number in a sorted array. If present, Return Yes with the index of element's index
# Else return No

# Program using Recursive Binary Search

# Returns True for Yes and False for No


def BinarySearch(arr, left, right, NumSquare):

    # check for preventing infinite recursive loop
    if right >= left:

        mid = left + (right - left) // 2

        # If element is present at the middle itself
        if arr[mid] == NumSquare:
            return True

        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid] > NumSquare:
            return BinarySearch(arr, left, mid - 1, NumSquare)

        # Else the element can only be present
        # in right subarray
        else:
            return BinarySearch(arr, mid + 1, right, NumSquare)

    # Element not present in array
    else:
        return False


# input a sorted array. A sorted array is either of ascending order or descending order
arr = [int(x) for x in input().split()]

left = 0  # left index
Num = int(input())  # Number whose square is to be searched for
NumSquare = Num * Num

# Function CAll
result = BinarySearch(arr, 0, len(arr) - 1, NumSquare)

# check for True
if result:
    print("Yes! " + "The index of square of {} is {}".format(Num, arr.index(Num * Num)))

# For false
else:
    print("No")
