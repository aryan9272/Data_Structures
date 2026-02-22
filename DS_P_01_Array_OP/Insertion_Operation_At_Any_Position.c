#include<stdio.h>
int main()
{
    int arr[100];
    int n,i,j,e;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter The Array Element:\n");
    for ( i = 0; i < n; i++)
    {
            scanf("%d",&arr[i]);

    }
    printf("Enter the Element that is to be Inserted:\n");
    scanf("%d",&e);
    printf("Enter the position where the Element is to be inserted:\n");
    scanf("%d",&j);
    n++;
    for ( i = n-1; i >= j; i--)
    {
      arr[i]=arr[i-1];
    }
    arr[j-1]=e;
         printf("Array After Insertion At The Given Position:\n");
   for ( i = 0; i < n; i++)
    {
            printf("%d\t",arr[i]);

    }
      return 0;
  
}
