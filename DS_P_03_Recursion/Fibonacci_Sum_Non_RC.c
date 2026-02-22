//Fibonacci_Sum_Non_RC

#include<stdio.h>
int Fibonacci(int n)
{
   if (n==1)
   {
     return 0;
   }
   else if(n==2)
   {

   
     return 1;
   
   }
   else
   {
int n1=0,n2=1,n3;
for (int  i = 3; i <=n; i++)
{
   n3=n1+n2;
   n1=n2;
   n2=n3;
   
}
return n3;
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