#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List ─────
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int inDegree[MAX];   // number of incoming edges per node
int n, m;

// ───── Queue ─────
int queue[MAX];
int front = 0, rear = 0;
void enqueue(int v)  { queue[rear++] = v;     }
int  dequeue()       { return queue[front++]; }
int  isEmpty()       { return front == rear;  }

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── DIRECTED edge u → v ─────
void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next   = adjList[u];
    adjList[u]   = node;
    inDegree[v]++;   // v has one more incoming edge
}

// ───── Kahn's Algorithm ─────
void kahnTopoSort() {

    // Step 1: enqueue all nodes with in-degree 0
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            enqueue(i);

    int result[MAX];
    int count = 0;   // tracks how many nodes processed

    // Step 2: BFS
    while (!isEmpty()) {
        int curr = dequeue();
        result[count++] = curr;   // add to topo order

        // Reduce in-degree of all neighbours
        struct Node* temp = adjList[curr];
        while (temp != NULL) {
            int nb = temp->vertex;
            inDegree[nb]--;           // remove curr's contribution

            if (inDegree[nb] == 0)   // all prereqs done → ready!
                enqueue(nb);

            temp = temp->next;
        }
    }

    // Step 3: check result
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main() {
    printf("Enter vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adjList[i]  = NULL;
        inDegree[i] = 0;
    }

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    kahnTopoSort();
    return 0;
}