#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List Node ─────
struct Node {
    int vertex;
    struct Node* next;
};

// ───── Queue (simple circular array) ─────
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v)  { queue[rear++] = v;      }
int  dequeue()       { return queue[front++];  }
int  isEmpty()       { return front == rear;   }

// ───── Graph ─────
struct Node* adjList[MAX];
int visited[MAX];
int n, m;

// ───── Create new node ─────
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── Add undirected edge ─────
void addEdge(int u, int v) {
    struct Node* node = newNode(v);   // add v to u's list
    node->next  = adjList[u];
    adjList[u]  = node;

    node        = newNode(u);         // add u to v's list
    node->next  = adjList[v];
    adjList[v]  = node;
}

// ───── BFS from source ─────
void bfs(int src) {
    visited[src] = 1;    // mark source visited
    enqueue(src);        // push source into queue

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int curr = dequeue();        // pick front of queue
        printf("%d ", curr);         // process it

        // Visit all unvisited neighbours → add to queue
        struct Node* temp = adjList[curr];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;     // mark BEFORE enqueue
                enqueue(temp->vertex);          // explore later
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// ───── Main ─────
int main() {
    int s;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges   (m): ");
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    bfs(s);

    return 0;
}