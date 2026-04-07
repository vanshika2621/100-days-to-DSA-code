#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int numCourses;

// DFS to detect cycle
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < numCourses; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

// Main function
int canFinish(int num, int prerequisites[][2], int size) {
    numCourses = num;

    // initialize graph
    for (int i = 0; i < numCourses; i++)
        for (int j = 0; j < numCourses; j++)
            graph[i][j] = 0;

    // build graph (bi → ai)
    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][a] = 1;
    }

    // initialize arrays
    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // check each node
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 0; // cycle found
        }
    }

    return 1; // no cycle
}

// Driver code
int main() {
    int numCourses = 2;
    int prerequisites[][2] = {{1,0},{0,1}};
    int size = 2;

    if (canFinish(numCourses, prerequisites, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}