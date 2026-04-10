#include <stdio.h>
#include <stdlib.h>

#define MAX  100
#define INF  99999999

// ───── Weighted Adjacency List ─────
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* adjList[MAX];
int n, m;

struct Node* newNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->weight = w;
    node->next   = NULL;
    return node;
}

// ───── Add directed weighted edge ─────
void addEdge(int u, int v, int w) {
    // u → v with weight w
    struct Node* node = newNode(v, w);
    node->next   = adjList[u];
    adjList[u]   = node;

    // undirected → also v → u
    node         = newNode(u, w);
    node->next   = adjList[v];
    adjList[v]   = node;
}

// ───── Min Priority Queue (min-heap) ─────
typedef struct {
    int node;
    int dist;
} PQNode;

PQNode heap[MAX * MAX];
int heapSize = 0;

void swap(int a, int b) {
    PQNode tmp = heap[a];
    heap[a]    = heap[b];
    heap[b]    = tmp;
}

// ── Bubble up after insert ──
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist > heap[i].dist) {
            swap(parent, i);
            i = parent;
        } else break;
    }
}

// ── Bubble down after extract ──
void heapifyDown(int i) {
    while (1) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int small = i;

        if (left  < heapSize && heap[left].dist  < heap[small].dist) small = left;
        if (right < heapSize && heap[right].dist < heap[small].dist) small = right;

        if (small != i) { swap(i, small); i = small; }
        else break;
    }
}

void pqPush(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize++);
}

PQNode pqPop() {
    PQNode top   = heap[0];
    heap[0]      = heap[--heapSize];
    heapifyDown(0);
    return top;
}

int pqEmpty() { return heapSize == 0; }

// ───── Dijkstra ─────
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i]    = INF;
        visited[i] = 0;
    }

    dist[src] = 0;
    pqPush(src, 0);   // push source with distance 0

    while (!pqEmpty()) {
        PQNode curr = pqPop();          // get closest unvisited node
        int u       = curr.node;

        if (visited[u]) continue;       // already processed → skip
        visited[u] = 1;

        // Relax all neighbours of u
        struct Node* temp = adjList[u];
        while (temp != NULL) {
            int v    = temp->vertex;
            int w    = temp->weight;

            // Found shorter path to v through u?
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pqPush(v, dist[v]);     // push updated distance
            }
            temp = temp->next;
        }
    }

    // Print results
    printf("\nShortest distances from source %d:\n", src);
    printf("Node\tDistance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("  %d\t  INF (unreachable)\n", i);
        else
            printf("  %d\t  %d\n", i, dist[i]);
    }
}

// ───── Main ─────
int main() {
    int src;

    printf("Enter vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter %d edges (u v w):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);
    return 0;
}