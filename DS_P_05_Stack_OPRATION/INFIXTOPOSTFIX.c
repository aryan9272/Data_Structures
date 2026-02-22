#include<stdio.h>
#include<string.h>
#define max 50
char stack[max];
int top=-1;

void push(char x)
{
    if(top==max-1)
    {
        printf("Stack Overflow....\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
int pop()
{
    if (top==-1)
    {
        printf("Stack Underflow....\n");
    }
    else{
        int y;
        y=stack[top];
        top--;
        return y;
    }
    
}
int precendece_order(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
    }
    else if (c=='*'||c=='/')
    {
         return 2;
    }
    else if (c=='^')
    {
        return 3;
    }
        return 0;
    
}

void in_post(char infix[])
{
char postfix[max];
char c;
int k=0;
for (int i = 0; infix[i]!='\0'; i++)
{
    c=infix[i];
    // i have put here a checker to check it is 'operand' or 'exp'
 if ((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
    {
        postfix[k++]=c;
    } 
else if (c=='(')
{
    push(c);
}
else if(c==')')
{
    while (top!=-1 && stack[top]!='(')
    {
         postfix[k++]=pop();
    }
    pop(); //yaha parentheses ke andar ka sara khatam ho gaya (exited..!)
}
else{
while (top!=-1 && precendece_order(stack[top])>=precendece_order(c))
{
        postfix[k++]=pop();
}
push(c);
}
}
while (top!=-1)//lastly we empty stack
{
      postfix[k++]=pop();
}
postfix[k] = '\0';
    printf("Postfix exp: %s\n", postfix);


}

int main()
{
    char infix[max];
    printf("Enter The infix exp:\n");
    scanf("%s",infix);
    in_post(infix);

}