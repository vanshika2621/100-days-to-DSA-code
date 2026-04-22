#include <stdio.h>

#define INF 1000000000

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int dist[105][105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int result = -1;
    int minCount = INF;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;
        }

        if (count <= minCount) {
            minCount = count;
            result = i;
        }
    }

    return result;
}

int main() {
    int n, edgesSize, distanceThreshold;
    scanf("%d", &n);
    scanf("%d", &edgesSize);

    int edges[1000][3];

    for (int i = 0; i < edgesSize; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    scanf("%d", &distanceThreshold);

    int result = findTheCity(n, edges, edgesSize, distanceThreshold);
    printf("%d\n", result);

    return 0;
}