#include<stdio.h>
int main()
{
    
    int arr[100];
    int sort=1,n;
    int temp;
    printf("Enter Size Of Array:\n");
    scanf("%d",&n);
    printf("Enter The Array Element :\n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
printf("Which Sorting Operation You Have to Perform...?\n");
printf("Enter 1 : For Basic Selection Sort.\n");
printf("Enter 2 : For Advance Selection Sort.\n");
printf("Enter 3 : For Bubble Sort.\n");
printf("Enter 4 : For Basic Insertion Sort.\n");
printf("Enter 5 : For Advance Insertion Sort.\n");
scanf("%d",&sort);

    switch (sort)
    {
        case 1: //Basic Selection Sort
        printf("Performing Basic Selection Sort...\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (arr[j]<arr[i])
                {
                 temp=arr[i];
                 arr[i]=arr[j];
                 arr[j]=temp;
                }
                
            }
            
        }
    
        for (int i = 0; i < n; i++)
        {
           printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("Array Sorted By Basic Selection Sort...\n");
         break;
        case 2: //Advance Selection Sort
         printf("Performing Advance Selection Sort...\n");
         int min;
         for (int i = 0; i < n; i++)
         {
            min=i;
            for (int j = i+1; j < n; j++)
            {
                if(arr[j]<arr[min])
              {
                 min=j;
              } 
              
            }
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
            
         }
          for (int i = 0; i < n; i++)
        {
           printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("Array Sorted By Advance Selection Sort...\n");
         
         break;
        case 3: //Bubble Sort
         printf("Performing Bubble Sort...\n");
         for (int i = 0; i < n-1; i++)
         {
            for (int j = 0; j < n-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                }
            }
            
         }
         for (int i = 0; i < n; i++)
        {
           printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("Array Sorted By Bubble Sort...\n");
         
         break;
        case 4: //Basic Insertion Sort
         printf("Performing Basic Insertion Sort...\n");
         for (int i = 1; i < n; i++)
         {
           for (int j = i-1; j < i; j++)
           {
            if (arr[i]<arr[j])
            {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
            }
            
           }
           
         }
         for (int i = 0; i < n; i++)
        {
           printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("Array Sorted By Basic Insertion Sort...\n");
         
         break;
        case 5: //Advance Insertion Sort
        printf("Performing Advance Insertion Sort...\n");
        int key,j;
        for (int i = 1; i < n; i++)
        {   key=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j=j-1;
                arr[j+1]=key;
            }
        }
        for (int i = 0; i < n; i++)
        {
           printf("%d\t",arr[i]);
        }
        printf("\n");
        printf("Array Sorted By Advance Insertion Sort...\n");
         break;
        default:
        printf("INVALID OPERATION...!\n");
         break;
    }

}