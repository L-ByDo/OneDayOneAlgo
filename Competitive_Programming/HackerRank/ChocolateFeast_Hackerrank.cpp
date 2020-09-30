#include <iostream>
using namespace std;

 
int
main ()
{
  
 
long int test, money, cost, wrappers, number, temp;
  
cin >> test;
  
for (int i = 0; i < test; i++)
    {
      
cin >> money >> cost >> wrappers;
      
long int number = money / cost;	//number of chocolates
      long int wrappers_to_new = wrappers;	//wrappers to buy new chocolate
      long int wrappers_present = number;	//wrappers currently present
      while (wrappers_present >= wrappers_to_new)
	{
	  
temp = wrappers_present / wrappers_to_new;
	  
number += wrappers_present / wrappers_to_new;
	  
wrappers_present = temp + (wrappers_present % wrappers_to_new);
	
 
}
      
cout << number << "\n";
    
}

 
}
