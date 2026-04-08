#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int adj[MAX][MAX];
int visited[MAX];
int result[MAX];
int idx;

int dfs(int v, int n) {
    if (visited[v] == 1) return 0;
    if (visited[v] == 2) return 1;

    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!dfs(i, n)) return 0;
        }
    }

    visited[v] = 2;
    result[idx--] = v;
    return 1;
}

int* findOrder(int numCourses, int prerequisites[][2], int prerequisitesSize, int* returnSize) {
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < numCourses; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][a] = 1;
    }

    idx = numCourses - 1;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, numCourses)) {
                *returnSize = 0;
                return NULL;
            }
        }
    }

    *returnSize = numCourses;

    int* ans = (int*)malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        ans[i] = result[i];
    }

    return ans;
}

int main() {
    int numCourses, prerequisitesSize;
    scanf("%d", &numCourses);
    scanf("%d", &prerequisitesSize);

    int prerequisites[prerequisitesSize][2];

    for (int i = 0; i < prerequisitesSize; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    int returnSize;
    int* order = findOrder(numCourses, prerequisites, prerequisitesSize, &returnSize);

    if (returnSize == 0) {
        printf("[]");
    } else {
        printf("[");
        for (int i = 0; i < returnSize; i++) {
            printf("%d", order[i]);
            if (i != returnSize - 1) printf(",");
        }
        printf("]");
    }

    free(order);
    return 0;
}