#include<iostream>
using namespace std;
int
fun (int arr[], int n, int k)
{
  int subset[n][k + 1];
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= k; j++)
	{
	  if (i == 0)
	    {
	      subset[i][j] = j;
	    }
	  else if (j == 0)
	    {
	      subset[i][j] = 0;	//we don't require any coin to make sum 0
	    }
	  else if (j < arr[i])
	    {
	      subset[i][j] = subset[i - 1][j];	//copy above value
	    }
	  else
	    {
	      subset[i][j] = min (subset[i - 1][j], 1 + subset[i][j - arr[i - 1]]);	//take one itself and the remaining one after this
	    }
	}
    }
  return subset[n][k];
}

int
main ()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
  int k = 10;
  int n = 5;
  cout << fun (arr, n, k);
}
