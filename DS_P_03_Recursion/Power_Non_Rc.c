#include<stdio.h>
int power(int a,int b)
{ int num=1;
while(b!=0)
{
num=num*a;
b--;
}
return num;
}


int main()
{
int a,b;
printf("Enter the No. :\n");
scanf("%d",&a);
printf("Enter the Power : \n");
scanf("%d",&b);
printf("Result=%d",power(a,b));

    return 0;
}