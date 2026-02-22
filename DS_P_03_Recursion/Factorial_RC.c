// Factorial_RC

#include<stdio.h>
int Factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    return n*Factorial(n-1);
    
}
int main()
{
int n;
printf("Enter a Number:\n");
scanf("%d",&n);
printf("Factorial=%d",Factorial(n));
return 0;
}