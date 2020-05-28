# # Python program for implementation of Quicksort Sort
#
# # This function takes last element as pivot, places
# # the pivot element at its correct position in sorted
# # array, and places all smaller (smaller than pivot)
# # to left of pivot and all greater elements to right
# # of pivot
# def partition(arr, low, high):
#     i = (low - 1)  # index of smaller element
#     pivot = arr[high]  # pivot
#
#     for j in range(low, high):
#
#         # If current element is smaller than the pivot
#         if arr[j] < pivot:
#             # increment index of smaller element
#             i = i + 1
#             arr[i], arr[j] = arr[j], arr[i]
#
#     arr[i + 1], arr[high] = arr[high], arr[i + 1]
#     return (i + 1)
#
#
# # The main function that implements QuickSort
# # arr[] --> Array to be sorted,
# # low --> Starting index,
# # high --> Ending index
#
# # Function to do Quick sort
# def quickSort(arr, low, high):
#     if low < high:
#         # pi is partitioning index, arr[p] is now
#         # at right place
#         pi = partition(arr, low, high)
#
#         # Separately sort elements before
#         # partition and after partition
#         quickSort(arr, low, pi - 1)
#         quickSort(arr, pi + 1, high)
#
#     # Driver code to test above
#
#
# arr = [10, 7, 8, 9, 1, 5]
# n = len(arr)
# quickSort(arr, 0, n - 1)
# print("Sorted array is:")
# for i in range(n):
#     print("%d" % arr[i]),
#
# def partition(arr,low,high):
#     pivot = arr[low]
#     i = low
#     j = high
#     while i<j:
#         while True:
#             i+=1
#             if pivot>=arr[i]:
#                 continue
#             else:
#                 break
#
#         while True:
#             j -= 1
#             if pivot<arr[j]:
#                 continue
#             else:
#                 break
#
#         if i<j:
#             arr[i], arr[j] = arr[j], arr[i]
#         print(arr)
#     arr[low], arr[j] = arr[j], arr[low]
#     return j
#
#
# def quicksort(arr, low, high):
#
#     if low<high:
#         j = partition(arr, low, high)
#         quicksort(arr, low, j)
#         quicksort(arr, j+1, high)
#
#
# if __name__ == "__main__" :
#     arr= [int(x) for x in input().split()]
#     quicksort(arr,0,len(arr))
#     print(arr)
def partition(arr,low,high):
    '''
    This functions takes up the lower and higher indices respectively and returns an array with the pivot element
    arranged such that all the elements less than it are on left and the greater one on right.
    :param arr: Array
    :param low: initially set to 0
    :param high: initially taken as length of array
    :return:
    '''

    #Pivot element can be any of the element of the array, here it is the element at 0th index
    pivot = arr[low]

    i = low
    j = high

    #while true act as a do while loop for python
    while True:
        i+=1
        if i<len(arr):
            if pivot>=arr[i]:
                continue
            else:
                break
        else:
            break

    while True:
        j -= 1
        if j>0:
            if pivot<arr[j]:
                continue
            else:
                break
        else:
            break

    if i<j:
        arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    return j


def quicksort(arr, low, high):

    if low<high:
        j = partition(arr, low, high)
        quicksort(arr, low, j)
        quicksort(arr, j+1, high)

#input array
arr= [int(x) for x in input().split()]

#Function Call
quicksort(arr,0,len(arr))
print(arr)