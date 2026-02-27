/*
Problem: Merge Two Sorted Linked Lists
*/

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter the elements in the linked list :");
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

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m;

    printf("Enter the size of first linked list");
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    printf("Enter the size of second linked list");
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* merged = mergeLists(list1, list2);

    // Print merged list
    while (merged != NULL) {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}