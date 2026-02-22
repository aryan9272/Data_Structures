#include <stdio.h>

int main() 
{
int arr[100];
int s,n,i,found=0,position=-1;
printf("Enter the size of array:\n");
scanf("%d",&n);
printf("Enter the array element:\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("Enter the Search element:\n");
scanf("%d",&s);
for(int i=0;i<n;i++)
{
 if(s==arr[i])
 {
  found=1;
  position=i+1;
  break;
 }
}
if(found==1)
{
    printf("%d is found at position %d in given array:\n",s,position);
    
}
else{
    printf("Error Element Not Found...!\n");
}
    return 0;
}