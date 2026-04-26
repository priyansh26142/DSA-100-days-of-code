#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* size, int* visited) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, size, visited);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * sizeof(int));
    }

    // input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int s;
    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));

    dfs(s, adj, size, visited);

    return 0;
}