# Selection Sort to find to sort an unsorted array


def SelectionSort(arr):
    # Traverse through all array elements
    for i in range(len(arr)):

        # Find the minimum element in remaining
        # unsorted array
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j

        # Swap the found minimum element with
        # the first element
        arr[min_index], arr[i] = arr[i], arr[min_index]

    print(arr)


if __name__ == "__main__":

    # input an unsorted array
    arr = [int(x) for x in input().split()]
    # Function Call
    SelectionSort(arr)
