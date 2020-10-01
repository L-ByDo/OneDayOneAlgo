//Sieve of Eratosthenes
// Prints all prime numbers <= N
#include<stdio.h>
int main(void)
{
    int n,i,j;


    printf("Enter the last number \n");
    scanf("%d", &n);

    int prime[n+1];
    for (i=2 ; i<=n ; i++)                              // Storing natural numbers in array
    {
        prime[i] = i;
    }
    i=2;
    while(i*i <= n)
    {

        // nested loop
        for(j=2 ; j<= n ; j++)
        {
            if (prime[i]*j > n)

                break;


            else prime[prime[i]*j] = 0;                   //Equating all multiples to 0 so we can print out non zero numbers

        }


        i++;

    }
    for (i=2 ; i<= n ; i++)
    {
        if (prime[i]!= 0)
        {
            printf("%d \n", prime[i]);
        }

    }




}