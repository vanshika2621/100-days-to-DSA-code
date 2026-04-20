#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;
Node** transpose;
int* visited;
int* stackArr;
int top = -1;

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs1(int u) {
    visited[u] = 1;
    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) dfs1(temp->v);
        temp = temp->next;
    }
    stackArr[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    Node* temp = transpose[u];
    while (temp) {
        if (!visited[temp->v]) dfs2(temp->v);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    transpose = (Node**)malloc(V * sizeof(Node*));
    visited = (int*)malloc(V * sizeof(int));
    stackArr = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        transpose[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp) {
            addEdge(transpose, temp->v, i);
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) visited[i] = 0;

    int count = 0;

    while (top != -1) {
        int node = stackArr[top--];
        if (!visited[node]) {
            dfs2(node);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}