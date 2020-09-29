#include<iostream>
using namespace std;
int
longest (int arr[], int n)
{
  int c[5];
  c[0] = 1;
  for (int i = 1; i < n; i++)
    {
      c[i] = 0;
    }

  for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
	{			//loop till i 

	  if (arr[i] > arr[j] && c[j] + 1 > c[i])
	    {			//if current length of sequence is smaller than jth length and current element is larger
	      c[i] = c[j] + 1;	//replace with jth length +1 bcz every element is longest subsequence in itself
	    }
	}
    }
  int max = c[0];		//find maximum element in count array
  for (int i = 1; i < n; i++)
    {
      if (c[i] > max)
	{
	  max = c[i];
	}
    }
  return max;
}

int
main ()
{
  int arr[6] = { 30, 29, 28, 31, 26, 25 };
  cout << longest (arr, 6);
}
