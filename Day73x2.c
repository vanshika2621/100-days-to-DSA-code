#include <stdio.h>

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py)
        parent[px] = py;
}

int main() {
    int n;
    scanf("%d", &n);

    int edges[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int parent[n + 1];
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int ans[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)) {
            ans[0] = u;
            ans[1] = v;
        } else {
            unionSet(parent, u, v);
        }
    }

    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}