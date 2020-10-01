//program in C to implement Euclidean algorithm in finding the greatest common divisor
#include<stdio.h>
int gcd(int num1,int num2)
{
    if(num1>num2)
        //implementing the base and recursive cases
        return num2==0? num1 : gcd(num2,num1%num2);
}

int main()
{
    int num1=20,num2=15;
    int result=gcd(num1,num2);
    printf("The greatest common divisor between 20 and 15 is %d. ",result);
    return 0;
}
