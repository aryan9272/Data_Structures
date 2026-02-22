#include<stdio.h>
#define max 5
int arr[max],top=-1;

void push()
{
    int x;
 if(top==max-1)
    {
        printf("Stack Overload...!\n");
    }
    else
    {
        top++;
        printf("Enter the element that is to be pushed:\n");
        scanf("%d",&x);
        arr[top]=x;
    }
}

void pop()
{
    int y;
 if(top==-1)
    {
        printf("Stack Underload...!\n");
    }
    else
    {
        y=arr[top];
        top--;
        printf("%d is popped from the stack\n",y);
    }
}
int main()
{
    push();
    push();
    push();
    pop();
    pop();
    pop();
    pop();

return 0;

}