#include<stdio.h>
int main()
{
    int size,m,n,mid;
    printf("Enter Size Of Array:\n");
    scanf("%d",&size);
    char arr[size];
    printf("Enter Array Element:\n");
    for (int i = 0; i < size; i++)
    {
        scanf(" %c",&arr[i]);
    }
    printf("Enter the 'm' element that is to be sorted in Ascending Order:\n ");
    scanf("%d",&m);
    printf("Enter the 'n' element that is to be sorted in Descending Order:\n ");
    scanf("%d",&n);
     if (m+n <= size) {
        
     for (int i = 0; i < m; i++)
    {
     for (int j = i+1; j < m; j++)
     {
       if (arr[j]<arr[i])
       {
        char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       } 
     }
    }
    for (int i = size-n; i < size; i++)
    {
     for (int j = i+1; j < size; j++)
     {if (arr[j]>arr[i])
       {  char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       } 
     }
    }
    mid=size/2;
    //Left
    for (int i = m; i < mid; i++)
    {for (int j = i+1; j < mid; j++)
     {if (arr[j]>arr[i])
       {char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       } 
     }
    }
    //Right
    for (int i = mid; i < size-n; i++)
    {
     for (int j = i+1; j < size-n; j++)
     { if (arr[j]<arr[i])
       {char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       } 
     }
    }
    for (int i = 0; i < size; i++)
    {   printf("%c\t",arr[i]);
    }
  }
  else{
printf("Invalid input: m + n cannot be greater than total size.\n");
  }
     return 0;
} 
