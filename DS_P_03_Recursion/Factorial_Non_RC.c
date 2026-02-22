// Factorial_Non_RC

#include<stdio.h>
int Factorial(int n)
{
    int fact=1;
    for (int i = 1; i <=n; i++)
    {
       fact=fact*i;
       
    }
    return fact;
    
}
int main()
{
int n;
printf("Enter a Number:\n");
scanf("%d",&n);
printf("Factorial=%d",Factorial(n));
return 0;
}