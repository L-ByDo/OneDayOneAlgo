# Radix Sort

Radix sort is an integer sorting algorithm that sorts data with integer keys by groupin Radix sort uses counting sort as a subroutine to sort an array of numbers. 
Because integers can be used to represent strings (by hashing the strings to integers), radix sort works on data types other than just integers.The lower bound of all the comparison based sorting algorithms( Merge sort, Heap sort, Quick sort, ...etc) is Ω(nLogn), i.e.., cannot be better than nLogn.

## The Radix Sort Algorithm
1) Do following for each digit i where i varies from least significant digit to the most significant digit.

 - Sort input array using counting sort (or any stable sort) according to the i’th digit.

Let us understand it with the help of an example.

```javascript
Original, unsorted list:

170, 45, 75, 90, 802, 24, 2, 66
Sorting by least significant digit (1s place) gives: [*Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75.]

170, 90, 802, 2, 24, 45, 75, 66
Sorting by next digit (10s place) gives: [*Notice that 802 again comes before 2 as 802 comes before 2 in the previous list.]

802, 2, 24, 45, 66, 170, 75, 90
Sorting by most significant digit (100s place) gives:

2, 24, 45, 66, 75, 90, 170, 802
```
## The complexity of Radix Sort Technique
  - Time Complexity: O(nk)
  - Space Complexity: O(n+k)
## Input Output Format
  - Input − An array of data, and the total number in the array, digit count of max number

  - Output − Sorted array.
  
## Example

  ### Input:
     The unsorted list: 802 630 20 745 52 300 612 932 78 187
  ### Output:
     Data before Sorting: 802 630 20 745 52 300 612 932 78 187
     Data after Sorting: 20 52 78 187 300 612 630 745 802 932
