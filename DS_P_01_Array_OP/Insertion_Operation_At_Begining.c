#include<stdio.h>
int main()
{
    int arr[100];
    int n,i,e;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter The Array Element:\n");
    for ( i = 0; i < n; i++)
    {
            scanf("%d",&arr[i]);

    }
    printf("Enter the Element that is to be inserted:\n");
    scanf("%d",&e);

    n++;
    for ( i = n-1; i >= 0; i--)
    {
      arr[i]=arr[i-1];
    }
    arr[0]=e;
         printf("Array After Insertion At Begining:\n");
   for ( i = 0; i < n; i++)
    {
            printf("%d \t",arr[i]);

    }
      return 0;
  
}
