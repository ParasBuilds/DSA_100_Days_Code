/*
Problem: Count Nodes in Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;
    int count = 0;

    // Create linked list and count nodes in single pass
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        int value;
        printf("Node %d: ", i + 1);
        scanf("%d", &value);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
        count++;  // Count during creation
    }

    printf("Number of nodes in the linked list: %d\n", count);

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}