#include <stdio.h>

int main() 
{ 
int arr[100];
int n;
printf("Enter the size of array:\n");
scanf("%d",&n);
printf("Enter the array element:\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("All odd no. from the array that you entered:\n");
for(int i=0;i<n;i++)
{ if(arr[i]%2!=0)
 {
     printf("%d\t",arr[i]);
 }
}

    return 0;
}
