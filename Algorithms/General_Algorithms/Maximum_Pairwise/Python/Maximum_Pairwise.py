# given code implements maximum pairwise sum to find maximum possible sum..for this, first sort an array and print sum of last two numbers.
def quicksort(seq):  # function to sort array
    length = len(seq)
    if length <= 1:
        return seq
    else:
        pivot = seq.pop()  # take out the pivot element
    great = []
    low = []

    def fun(seq, low, great):
        if len(seq) == 0:
            return
        elif seq[0] > pivot:
            great.append(seq[0])
        else:
            low.append(seq[0])
        return fun(seq[1:], low, great)
    fun(seq, low, great)
    return quicksort(low)+[pivot]+quicksort(great)


arr = [-4, 5, -78, -65, 2, -56, 788, 67, 0, 75]
arr = quicksort(arr)
print(arr)
print(arr[-1]+arr[-2])  # print sum of last two numbers
