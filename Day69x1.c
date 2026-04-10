#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 105
#define MAXE 6005

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

Edge adj[MAXN][MAXN];
int adjSize[MAXN];

HeapNode heap[MAXE];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(HeapNode x) {
    heap[++heapSize] = x;
    int i = heapSize;
    while(i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while(1) {
        int smallest = i;
        int l = 2*i, r = 2*i + 1;

        if(l <= heapSize && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if(r <= heapSize && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if(smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

int isEmpty() {
    return heapSize == 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for(int i = 1; i <= n; i++) adjSize[i] = 0;

    for(int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][adjSize[u]].v = v;
        adj[u][adjSize[u]].w = w;
        adjSize[u]++;
    }

    int k;
    scanf("%d", &k);

    int dist[n+1];
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX;

    dist[k] = 0;
    push((HeapNode){k, 0});

    while(!isEmpty()) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        if(d > dist[u]) continue;

        for(int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push((HeapNode){v, dist[v]});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) {
            printf("-1\n");
            return 0;
        }
        if(dist[i] > ans) ans = dist[i];
    }

    printf("%d\n", ans);
    return 0;
}