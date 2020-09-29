/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int
cal (int w[], int v[], int c)
{
  int n = 3;
  int subset[n + 1][c];
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= c; j++)
	{
	  if (i == 0 || j == 0)
	    {
	      subset[i][j] = 0;
	    }
	  else if (j >= w[i - 1])
	    {			//if capacity is greater than current value then put it and smaller ones
	      subset[i][j] =
		max (subset[i - 1][j - w[i - 1]] + v[i - 1],
		     subset[i - 1][j]);
	    }
	  else
	    {
	      subset[i][j] = subset[i - 1][j];	//else put smaller item
	    }
	}
    }
  return subset[n][c];

}

int
main ()
{
  int *w;
  int *v;
  int *c;
  w = new int[3];		//creating dynamic values
  v = new int[3];
  c = new int ();
  cout << "Enter weights";
  for (int i = 0; i < 3; i++)
    {
      cin >> w[i];
    }
  cout << "Enter values";
  for (int i = 0; i < 3; i++)
    {
      cin >> v[i];
    }
  cout << "Enter capacity";
  cin >> *c;
  cout << cal (w, v, *c);
  delete w;
  delete v;			//deleting the dynamic allocations
  delete c;
}
