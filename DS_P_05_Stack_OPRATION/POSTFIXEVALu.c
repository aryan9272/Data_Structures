#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -99999;  // special error value
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int b = pop();
            int a = pop();
            if (a == -99999 || b == -99999) {
                printf("Invalid expression!\n");
                return -1;
            }
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push((int)pow(a, b)); break;
                default: 
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
        }
    }
    if (top != 0) {
        printf("Invalid postfix expression!\n");
        return -1;
    }
    return pop();
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression (no spaces, single-digit numbers): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1)
        printf("Evaluated Result: %d\n", result);

    return 0;
}