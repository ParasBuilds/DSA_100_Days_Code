#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Linked List Node ─────
struct Node {
    int vertex;
    struct Node* next;
};

// ───── Graph Structure ─────
struct Node* adjList[MAX];   // array of head pointers (one per vertex)
int n, m;                    // vertices, edges

// ───── Create a new neighbour node ─────
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── Add edge (insert at beginning of list for O(1)) ─────
void addEdge(int u, int v, int directed) {

    // Add v to u's list
    struct Node* node = newNode(v);
    node->next    = adjList[u];   // new node points to old head
    adjList[u]    = node;         // new node becomes new head

    if (!directed) {
        // Add u to v's list (undirected → both ways)
        node          = newNode(u);
        node->next    = adjList[v];
        adjList[v]    = node;
    }
}

// ───── Print Adjacency List ─────
void printList() {
    printf("\nAdjacency List:\n");
    for (int i = 1; i <= n; i++) {
        printf("Vertex %d → ", i);

        struct Node* temp = adjList[i];
        while (temp != NULL) {
            printf("[%d]", temp->vertex);
            if (temp->next != NULL)
                printf(" → ");
            temp = temp->next;
        }
        printf(" → NULL\n");
    }
}

// ───── Main ─────
int main() {
    int directed;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges   (m): ");
    scanf("%d", &m);

    printf("Directed? (1 = Yes, 0 = No): ");
    scanf("%d", &directed);

    // Initialize all heads to NULL
    for (int i = 1; i <= n; i++)
        adjList[i] = NULL;

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v, directed);
    }

    printList();

    return 0;
}