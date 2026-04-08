#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ───── Adjacency List ─────
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// ───── Stack to store finish order ─────
int stack[MAX];
int top = -1;

void push(int v)  { stack[++top] = v; }
int  pop()        { return stack[top--]; }
int  isEmpty()    { return top == -1; }

int n, m;

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next   = NULL;
    return node;
}

// ───── DIRECTED edge only ─────
void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next  = adjList[u];
    adjList[u]  = node;
}

// ───── DFS → push to stack when fully explored ─────
void dfs(int curr) {
    visited[curr] = 1;

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }

    // All neighbours done → push current to stack
    push(curr);
}

int main() {
    printf("Enter vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Run DFS from every unvisited node
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    // Pop stack → topological order
    printf("Topological Order: ");
    while (!isEmpty())
        printf("%d ", pop());
    printf("\n");

    return 0;
}