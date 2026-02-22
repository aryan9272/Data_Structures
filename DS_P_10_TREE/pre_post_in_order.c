#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    struct Node* newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = insertNode();
    printf("Enter right child of %d:\n", data);
    newNode->right = insertNode();
    return newNode;
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
       }
}
int main() {
    struct Node* root = NULL;
    printf("Create the binary tree:\n");
    root = insertNode();
    printf("Preorder Traversal: ");
    preorder(root);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
