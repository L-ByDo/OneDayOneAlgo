/* Complexity of this approach:-
O(nlogn) + O(n^2) = O(n^2)*/
#include <bits/stdc++.h> 
using namespace std; 
  
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
    sort(A, A + arr_size); //Sorts the array.
    /* Now fix the first element one by one and find the 
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) 
    {
    	// To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        l = i + 1; 
        // index of the first element in the 
        // remaining elements 
        r = arr_size - 1; 
        // index of the last element 
        while (l < r) { 
            if (A[i] + A[l] + A[r] == sum) { 
                printf("Triplet is %d, %d, %d", A[i], 
                       A[l], A[r]); 
                return true; 
            } 
            else if (A[i] + A[l] + A[r] < sum) 
                l++; 
            else  
                r--; 
        } 
    }  
    //If no triplet found we return false
    return false; 
} 
  
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
    find3Numbers(A, arr_size, sum); 
    return 0; 
}