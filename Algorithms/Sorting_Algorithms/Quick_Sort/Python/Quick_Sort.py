def partition(arr, low, high):
    """
    This functions takes up the lower and higher indices respectively and returns an array with the pivot element
    arranged such that all the elements less than it are on left and the greater one on right.
    :param arr: Array
    :param low: initially set to 0
    :param high: initially taken as length of array
    :return:
    """

    # Pivot element can be any of the element of the array, here it is the element at 0th index
    pivot = arr[low]

    i = low
    j = high

    # while true act as a do while loop for python
    while True:
        i += 1
        if i < len(arr):
            if pivot >= arr[i]:
                continue
            else:
                break
        else:
            break

    while True:
        j -= 1
        if j > 0:
            if pivot < arr[j]:
                continue
            else:
                break
        else:
            break

    if i < j:
        arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    return j


def quicksort(arr, low, high):

    if low < high:
        j = partition(arr, low, high)
        quicksort(arr, low, j)
        quicksort(arr, j + 1, high)


# input array

arr = [int(x) for x in input().split()]

# Function Call
quicksort(arr, 0, len(arr))
print(arr)
