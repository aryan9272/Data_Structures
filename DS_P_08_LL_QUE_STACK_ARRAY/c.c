#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int x) {
    if (rear1 == MAX - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}
int dequeue1() {
    if (front1 == -1) return -1;
    int x = q1[front1++];
    if (front1 > rear1) front1 = rear1 = -1;
    return x;
}
int size1() { return (front1 == -1) ? 0 : (rear1 - front1 + 1); }

void enqueue2(int x) {
    if (rear2 == MAX - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}
int dequeue2() {
    if (front2 == -1) return -1;
    int x = q2[front2++];
    if (front2 > rear2) front2 = rear2 = -1;
    return x;
}
int size2() { return (front2 == -1) ? 0 : (rear2 - front2 + 1); }

void push(int x) {
    enqueue2(x);
    while (size1() != 0) {
        enqueue2(dequeue1());
    }
    // swap q1 and q2
    int tq[MAX]; int tf=front1, tr=rear1;
    for(int i=0;i<MAX;i++) tq[i]=q1[i];
    front1=front2; rear1=rear2;
    for(int i=0;i<MAX;i++) q1[i]=q2[i];
    front2=tf; rear2=tr;
    for(int i=0;i<MAX;i++) q2[i]=tq[i];
    printf("%d pushed\n", x);
}
void pop() {
    if (size1() == 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d popped\n", dequeue1());
}
void peek() {
    if (size1() == 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", q1[front1]);
}
void display() {
    if (size1() == 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
