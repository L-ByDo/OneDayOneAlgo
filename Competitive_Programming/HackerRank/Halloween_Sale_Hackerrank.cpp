#include<iostream>
using namespace std;

int
main ()
{
  
long int p, d, m, s, sum = 0, n = 0;
  
cin >> p >> d >> m >> s;
  
while (sum <= s)
    {				//till current price is smaller than balance
      if (p >= m)
	{			//if price is greater than minimum 
	  sum += p;
	  
    p -= d;
	  
    n += 1;		//increment item
	}
      
      else
	{
	  
     p = m;		//every item later costs same then
	 sum += p;
	  
 
 
        n += 1;
	
}
    
}
  
cout << n - 1;

}


