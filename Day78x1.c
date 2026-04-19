#include <stdio.h>
#include <stdlib.h>

int **adj;
int *vis;
int n;

void dfs(int node){
    vis[node] = 1;
    for(int i = 1; i <= n; i++){
        if(adj[node][i] && !vis[i]){
            dfs(i);
        }
    }
}

int main(){
    int m;
    scanf("%d %d", &n, &m);

    adj = (int**)malloc((n + 1) * sizeof(int*));
    for(int i = 0; i <= n; i++){
        adj[i] = (int*)calloc(n + 1, sizeof(int));
    }

    vis = (int*)calloc(n + 1, sizeof(int));

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}