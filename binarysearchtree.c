#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int value) {
    // Base case: root is null or the value is found
    if (root == NULL || root->value == value) {
        return root;
    }

    // If the value is greater, search in the right subtree
    if (value > root->value) {
        return search(root->right, value);
    }

    // Otherwise, search in the left subtree
    return search(root->left, value);
}

// In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

// Main function to test the BST operations
int main() {
    struct Node* root = NULL;
    int n, value, key;

    // Ask the user for the number of elements to insert into the BST
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Insert the values provided by the user
    printf("Enter %d values to insert into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display the tree in various orders
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    // Searching for a value in the BST
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

