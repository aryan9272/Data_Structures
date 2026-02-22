#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to sort linked list using Bubble Sort
void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to remove duplicates in sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Main Function
int main() {
    struct Node* head = NULL;

    // Example Input
    insertEnd(&head, 30);
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 20);
    insertEnd(&head, 10);
    insertEnd(&head, 40);

    printf("Original List:\n");
    printList(head);

    sortList(head);
    printf("\nSorted List:\n");
    printList(head);

    removeDuplicates(head);
    printf("\nList After Removing Duplicates:\n");
    printList(head);

    return 0;
}
