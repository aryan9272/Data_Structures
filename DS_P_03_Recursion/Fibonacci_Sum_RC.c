//Fibonacci_Sum_RC

#include<stdio.h>
int Fibonacci(int n)
{

if(n==1)
{
return 0;
}
else if(n==2)
{
return 1; 
}
else
{
    return Fibonacci(n-1)+Fibonacci(n-2);
}

}

int main()
{
int n;
int sum=0;
printf("Enter a Number:\n");
scanf("%d",&n);
printf("Sum of Fibonacci Series upto %dth term :\n",n);

for (int i = 1; i <=n; i++)
{
   sum=sum+Fibonacci(i); 
}

printf("%d",sum);
return 0;
}