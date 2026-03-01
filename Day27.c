#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements:\n", n);
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

// Count length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection by value
void findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Traverse both together
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            return;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
}

int main() {

    int n, m;

    printf("Enter the number of elements for first list: ");
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    
    printf("Enter the number of elements for second list: ");
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}