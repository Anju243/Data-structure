#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  // Point the new node's next to the current head
    *head = newNode;        // Move the head pointer to the new node
}

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head) {
    // If the list is empty
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;  // Move the head pointer to the next node
    free(temp);             // Free the memory of the old head
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initially, the list is empty

    // Inserting nodes at the beginning
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAtFirst(&head, 50);

    // Displaying the linked list
    displayList(head);

    // Deleting the first node
    printf("Deleting the first node...\n");
    deleteFirst(&head);

    // Displaying the linked list after deletion
    displayList(head);

    // Deleting the first node again
    printf("Deleting the first node...\n");
    deleteFirst(&head);

    // Displaying the linked list after deletion
    displayList(head);

    return 0;
}
