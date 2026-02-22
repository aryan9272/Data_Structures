//Power_RC

#include<stdio.h>
int power(int a,int b)
{
if(b==0)
{
     return 1;
}
else{ 
//    b--;
return a*power(a,b-1);
}
}
int main()
{
int a,b;
printf("Enter the No. :\n");
scanf("%d",&a);
printf("Enter the Power:\n");
scanf("%d",&b);
printf("Result=%d",power(a,b));
    return 0;
}