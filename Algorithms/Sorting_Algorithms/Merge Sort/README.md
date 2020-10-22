# Merge Sort

## Why Merge Sort?
Merge sort is one of the most powerful sorting algorithms that you will encounter. In fact it is the native `.sort` algorithm used in many JavaScript environments (such as [Mozilla's](https://bugzilla.mozilla.org/show_bug.cgi?id=224128)). It compares a list of elements using a "Divide and Conquer" strategy.



## How does it work?
Merge Sort works on the basic principal of dividing a list into sub-lists until your sub-lists are of length one or zero. Once your sub-lists are at that size, you merge with a neighboring sub-list. *Note, lists of size one are techinically already sorted.*


## Visualizations
![merge-sort-visualization](https://camo.githubusercontent.com/c9d3bf4590b7284596375ffa0cd98ee62699a757/68747470733a2f2f776562646f63732e63732e75616c62657274612e63612f253745686f6c74652f5432362f4c65637475726536466967362e676966)



## How would I build it?

-  A `mergeSort` function may take an array, cut it in half [recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)) until it has divided the whole array into single items. At this point the recursive calls finally starts returning to the function that invoked it. At this point a separate helper function, `merge`, could be called on a pair of sorted arrays merging them together (see visualization above).
-  The `merge` function takes two *sorted* arrays as parameters (an array with one element is technically sorted), looks at the the first elements of the two lists, and assembles a resulting list based on the two lists "zipped" together by pushing the lowest to highest valued elements.

## Problem Statement
Implement Merge algorithm to sort an integer array.

## Input Format

 - First line:the size of the array
 - Second line:the array to be sorted(numbers seperated by spaces)

## Output Format

 - Return shorted array, each number seperated by a coma.

### Sample Input

6</br>
1 9 3 5 4 7

### Sample Output
[1,3,4,5,7,9]
