import random

def merge(left, right):

    result = []

    left_index, right_index = 0, 0
    
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            result.append(left[left_index])
            left_index += 1
        else:
            result.append(right[right_index])
            right_index += 1
 
    if left_index < len(left):
        result.extend(left[left_index:])
    
    if right_index < len(right):
        result.extend(right[right_index:])
    
    return result

def merge_sort(list_to_sort):
	if len(list_to_sort) <= 1:
		return list_to_sort

	middle = int(len(list_to_sort) / 2)
	left = merge_sort(list_to_sort[:middle])
	right = merge_sort(list_to_sort[middle:])

	return merge(left, right)

if __name__ == "__main__":
    data = [random.randint(1, 100) for i in range(15)]
    print(f'Unsorted List: {data}')
    sorted_list = merge_sort(data)
    print(f'Sorted List: {sorted_list}')
