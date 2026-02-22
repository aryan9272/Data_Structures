#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char expr[MAX];
    int i, balanced = 1;

    printf("Enter expression: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char popped = pop();
            if (!isMatchingPair(popped, expr[i])) {
                balanced = 0;
                break;
            }
        }
    }

    if (balanced && top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}

