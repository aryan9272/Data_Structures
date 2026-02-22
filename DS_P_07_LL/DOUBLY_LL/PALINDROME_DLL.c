#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(int value) 
{   
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
int isPalindrome() {
    if (head == NULL) return 1;  // empty list is palindrome
    // find tail
    struct Node* start = head;
    struct Node* end = head;
    while (end->next != NULL) end = end->next;
    // compare from both ends
    while (start != end && start->prev != end)
     {
        if (start->data != end->data) 
        return 0;
        start = start->next;
        end = end->prev; 
    }
    return 1;
}
void display() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");}
int main() {
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }
    display();                                                                                                                                                                                    
    if (isPalindrome()==1)
    {  printf("The linked list is a PALINDROME.\n");
    }
     else
        { printf("The linked list is NOT a palindrome.\n");
      }
    return 0;
}
