def InsertionSort(arr):
    """
    This function takes in the unsorted array, and returns the sorted array.
    :param arr: Unsorted array
    :return:    Sorted Array
    """

    # Run the loop till i reaches the end of the array.
    for i in range(len(arr)):
        # store the value of the encountered element to a variable key, to use it for comparison.
        key = arr[i]
        # Check the elements less than the index i
        j = i - 1
        # while l;oop for positive j value and for encountered element being greater than key
        while j >= 0 and key < arr[j]:
            # Shift the encountered element by one place, therefore creating a void in the j th index of the array
            arr[j + 1] = arr[j]
            # decrement in j so as to move to the next element in the array before the shofted element
            j -= 1
        # Insert the key in the void position left-put, after all elements greater than the key are shifted to the right
        arr[j + 1] = key

    # return the sorted array
    return arr


if __name__ == "__main__":
    # take input of array
    arr = [int(x) for x in input().split()]
    arr = InsertionSort(arr)
    # Print array
    for element in arr:
        print(element)
