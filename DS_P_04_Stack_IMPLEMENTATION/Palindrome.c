#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) 
{
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = c;
}
char pop() {
    char temp;
    if (top == -1) 
    {
        return '\0';
    }
    else
    {
        temp=stack[top];
        top--;
    return temp;
    }
}

void rev(char str[], char reversed[]) {
    int k = 0;
    top = -1;

    for (int i = 0; str[i] != '\0'; i++)
     {
        push(str[i]); 
    }

    while (top != -1)
    
{
        reversed[k++] = pop();
    }
    reversed[k] = '\0';
}

int main() {
    int palindrome=1;
    char str[MAX], reversed[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    rev(str, reversed);
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]!=reversed[i])
        {
            palindrome=0;
            break;
        }
    }
    if(palindrome==1)
    {
        printf("palindrome");
    }
    else{
        printf("NOT palindrome");
    }

    return 0;
}
