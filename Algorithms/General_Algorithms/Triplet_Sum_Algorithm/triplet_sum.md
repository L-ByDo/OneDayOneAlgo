 This method uses sorting to increase the efficiency of the code.

Approach: By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take linear time so it is better than a nested loop.

Algorithm :
1. Sort the given array.
2. Loop over the array and fix the first element of the possible triplet, arr[i].
3. Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum,
   a. If the sum is smaller than the required sum, increment the first pointer.
   b. Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
   c. Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.
