#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Define an edge
typedef struct Edge {
    int v;
    int w;
    struct Edge* next;
} Edge;

// Define an adjacency list
typedef struct {
    Edge* head;
} AdjList;

// Structure for the priority queue node
typedef struct {
    int v;
    int dist;
} MinHeapNode;

// Structure for the priority queue
typedef struct {
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
} MinHeap;

// Function to create an edge
Edge* createEdge(int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = NULL;
    return newEdge;
}

// Function to create a Min Heap node
MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// Function to create a Min Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc((capacity + 1) * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc((capacity + 1) * sizeof(MinHeapNode*));
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Standard minHeapify function
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right <= minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract minimum node from heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    MinHeapNode* root = minHeap->array[1];
    MinHeapNode* lastNode = minHeap->array[minHeap->size];
    minHeap->array[1] = lastNode;

    minHeap->pos[root->v] = minHeap->size;
    minHeap->pos[lastNode->v] = 1;

    --minHeap->size;
    minHeapify(minHeap, 1);

    return root;
}

// Function to decrease key value of a given vertex v
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i > 1 && minHeap->array[i]->dist < minHeap->array[i / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = i / 2;
        minHeap->pos[minHeap->array[i / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[i / 2]);
        i = i / 2;
    }
}

// Function to check if a given vertex is in min heap or not
int isInMinHeap(MinHeap *minHeap, int v) {
    if (minHeap->pos[v] <= minHeap->size)
        return 1;
    return 0;
}

// Function that calculates distances of shortest paths
void dijkstra(int n, AdjList* graph, int src) {
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    MinHeap* minHeap = createMinHeap(n);

    for (int v = 1; v <= n; ++v) {
        dist[v] = INF;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = n;

    while (minHeap->size != 0) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        Edge* pCrawl = graph[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->v;
            if (isInMinHeap(minHeap, v) && dist[u] != INF && pCrawl->w + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->w;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
        free(minHeapNode);
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            printf("-1 ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");

    free(dist);
    free(minHeap->pos);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    AdjList* graph = (AdjList*)malloc((n + 1) * sizeof(AdjList));
    for (int i = 1; i <= n; i++) {
        graph[i].head = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        Edge* node1 = createEdge(v, w);
        node1->next = graph[u].head;
        graph[u].head = node1;

        Edge* node2 = createEdge(u, w);
        node2->next = graph[v].head;
        graph[v].head = node2;
    }
    
    int source;
    scanf("%d", &source);

    dijkstra(n, graph, source);

    for (int i = 1; i <= n; i++) {
        Edge* current = graph[i].head;
        while (current != NULL) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}
