#include <stdio.h>
#include <stdlib.h>
// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;   // start of the list
//  Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createList(int n) {
    int value;
    struct Node *newNode, *temp;
    if (n <= 0) {
        printf("Invalid size!\n");
        return;
    }
    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head = createNode(value);
    temp = head;
    // create remaining n-1 nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    printf("List created successfully with %d nodes.\n", n);
}
// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}
// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", value);
}
//  Insert at position
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;

    printf("%d inserted at position %d.\n", value, pos);
}

//  Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}
// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {  // only one node
        printf("%d deleted from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    printf("%d deleted from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
//  Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    printf("%d deleted from position %d.\n", temp->data, pos);
    if (temp->next != NULL)
    { 
     temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
     temp->prev->next = temp->next;
    }
    free(temp);
}
// Display list (forward & backward)
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Backward: NULL");
    while (temp != NULL) {
        printf(" <-> %d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    int choice, value, pos, n;
    printf("Enter number of nodes for initial list: ");
    scanf("%d", &n);
    createList(n);
    display();
    while (1) {
        printf("\nOPERATIONS for DLL\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at end\n");
        printf("3. Insert at Pos\n");
        printf("4. Delete at begin\n");
        printf("5. Delete at End\n");
        printf("6. Delete at pos\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
