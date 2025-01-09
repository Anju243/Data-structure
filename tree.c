#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};l
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value > root->value) {
        return search(root->right, value);
    }
    return search(root->left, value);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}
int main() {
    struct Node* root = NULL;
    int n, value, key;
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);
    printf("Enter %d values to insert into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");
    printf("Enter a value to search in the BST: ");
    scanf("%d", &key);
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node with value %d found in the BST.\n", key);
    } else {
        printf("Node with value %d not found in the BST.\n", key);
    }

    return 0;
}

