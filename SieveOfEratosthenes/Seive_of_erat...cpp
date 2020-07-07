#include<iostream>
using namespace std;
int
main ()
{
  int arr[11];
  int n = 10;
  for (int i = 0; i <= n; i++)
    {
      arr[i] = 1;
    }
  arr[0] = 0;   //0 and 1 are not prime
  arr[1] = 0;
  for (int i = 2; i <= n; i++)
    {
      if (arr[i] == 1)  //if it itself is not false
	{
	  for (int j = i; i * j <= n; j++)  
	    {
	      arr[i * j] = 0; //keep multiples of i as non-prime
	    }
	}
    }
  for (int i = 0; i <= n; i++)
    {
      if (arr[i] == 1)
	{
	  cout << i;
	}
    }
}
