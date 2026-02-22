#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow (can't type more)\n");
        return;
    }
    stack[++top] = c;
}

void undo() {
    if (top == -1) {
        printf("Nothing to undo!\n");
        return;
    }
    printf("Undo: '%c' removed\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Text is empty\n");
        return;
    }
    printf("Current text: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    char str[MAX];
    printf("Type some text: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    display();
    undo();
    display();
    undo();
    display();
    undo();
    display();

    return 0;
}