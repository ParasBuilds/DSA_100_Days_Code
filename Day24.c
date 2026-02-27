/*
Problem: Delete First Occurrence of a Key in Linked List

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    if (head == NULL)
        return head;

    struct Node *temp = head, *prev = NULL;

    // If head node contains key
    if (head->data == key) {
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    // Print updated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}