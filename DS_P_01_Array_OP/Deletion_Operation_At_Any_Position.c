#include <stdio.h>
int main() 
{
    int arr[100];
    int n, i,j;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
     printf("Enter the position of the array where the element is to be deleted:\n");
    scanf("%d", &j);
           for(i = j; i < n; i++)
           {
            arr[i-1]=arr[i];
           }
           n--;
    printf("Array after deleting element from the Begining:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
