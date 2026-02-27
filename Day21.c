/*
Problem: Create and Traverse Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter the size of linked list");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter the elements in the linked list :");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Traverse and print linked list
    temp = head;
    printf("Elements in the linked list :\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}