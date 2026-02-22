#include <stdio.h>
#define MAX 100
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
void push1(int x) {

stack1[++top1] = x; }
int pop1() { 
    return stack1[top1--]; }
void push2(int x) {
     stack2[++top2] = x; }
int pop2() {
     return stack2[top2--]; }

void enqueue(int x) {
    push1(x);
    printf("%d enqueued\n", x);
}
void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }
    printf("%d dequeued\n", pop2());
}
void peek() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }
    printf("Front element: %d\n", stack2[top2]);
}
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    return 0;
}
