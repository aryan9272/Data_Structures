// Fibonacci_Print_Non_RC

#include<stdio.h>
void Fibonacci(int n)
{
int n1=0,n2=1,n3;
if(n>=1)printf("%d ",n1);
if(n>=2)printf("%d ",n2);
for (int i = 3; i <=n; i++)
{
n3=n1+n2;
n1=n2;
n2=n3;
printf("%d ",n3);
}
}
int main()
{
    int n;
    printf("Enter a Number:\n");
    scanf("%d",&n);
    printf("Fibonacci Series upto %dth term :\n",n);
    Fibonacci(n);
    return 0;
}