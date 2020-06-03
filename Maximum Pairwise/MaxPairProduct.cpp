// C++ program to find maximum product pair in an array 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find maximum product pair in arr[0..n-1] 
int maxPairwiseProduct(int numbers[], int n) 
{
	int product;
	if (n < 2) 
	{ 
		cout << "No pairs exists\n";  
	} 

	if (n == 2) 
	{ 
		cout << numbers[0] << " " << numbers[1] << endl; 
	} 

	// Iniitialize maximum and second maximum 
	int pos1 = INT_MIN, pos2 = INT_MIN; 

	// Iniitialize minimum and second minimum 
	int neg1 = INT_MIN, neg2 = INT_MIN; 

	// Traverse given array 
	for (int i = 0; i < n; i++) 
	{ 
		// Update maximum and second maximum if needed 
		if (numbers[i] > pos1) 
		{ 
			pos2 = pos1; 
			pos1 = numbers[i]; 
		} 
		else if (numbers[i] > pos2) 
			pos2 = numbers[i]; 

		// Update minimum and second minimum if needed 
		if (numbers[i] < 0 && abs(numbers[i]) > abs(neg1)) 
		{ 
			neg2 = neg1; 
			neg1 = numbers[i]; 
		} 
		else if(numbers[i] < 0 && abs(numbers[i]) > abs(neg2)) 
			neg2 = numbers[i]; 
	} 
    if (neg1*neg2 > pos1*pos2) 
		{
			cout << "Max product pair is {" << neg1 << ", "
			<< neg2 << "}"; 
			product=neg1*neg2;
		}
	else
		{
			cout << "Max product pair is {" << pos1 << ", "
			<< pos2 << "}"; 
			product = pos1*pos2;
		}
	return product;
	} 

// Driver program to test above function 
int main() 
{ 
	int numbers[] = {1, 4 , 3 , -8 , 2 , -6 , 7 , 0}; 
	int n = 8; 
	int product=maxPairwiseProduct(numbers, n); 
	printf("\nMax is Product is %d",product);
	return 0; 
} 
