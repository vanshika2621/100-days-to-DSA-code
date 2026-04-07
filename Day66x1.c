#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V; // number of vertices

// DFS function to detect cycle
int isCyclicUtil(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            // If not visited, recurse
            if (!visited[i] && isCyclicUtil(i))
                return 1;
            // If already in recursion stack → cycle
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Main function to check cycle
int isCyclic() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    if (isCyclic())
        printf("Cycle detected in directed graph.\n");
    else
        printf("No cycle found.\n");

    return 0;
}