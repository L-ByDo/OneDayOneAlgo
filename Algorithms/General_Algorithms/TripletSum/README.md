In this question we need to find a triplet in a array which sums upto a given value 'K'.

Input:
1. We are given an array with n values.
2. We are given an integer K which is the sum we need to find.

Approach:
1. Naive approach is to use 3 for loops and compute the sums. Time complexity for that is O(n^3).
2. Approach discussed here is using binary search i.e we are selecting 2 values in beginning and apply binary search in array to find the last value. 
Time complexity discussion:-
Sorting : O(nlogn)
Searching and 2 values : O(n)
Searching last value : O(logn) as its binary search
Total : O(nlogn)