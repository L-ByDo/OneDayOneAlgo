#include<iostream>
using namespace std;
int
main ()
{
  int arr[4] = { 1, 2, 3, 4 }, j, q, n = 4, i;
  int subset[4][4];
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (i == 0 || j == 0 || i == j)
	    {
	      subset[i][j] = 0;
	    }
	}
    }
  for (int d = 1; d < n - 1; d++)
    {				//the difference should be smaller than 4 because last row is occupied
      for (i = 1; i < n - d; i++)
	{			//we first check (1,2),(2,3).. and then (1,3) (2,4) and so on
	  j = i + d;
	  subset[i][j] = 32767;
	  for (int k = i; k < j; k++)
	    {			//check every associative permutation 
	      q =
		subset[i][k] + subset[k + 1][j] + arr[i -
						      1] * arr[k] * arr[j];
	      if (q < subset[i][j])
		{
		  subset[i][j] = q;
		}
	    }
	}
    }
  cout << subset[1][n - 1];

}
