#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int** adj, int* size, int* state) {
    
    if (state[node] == 1)
        return 1; // cycle found

    if (state[node] == 2)
        return 0; // already processed

    state[node] = 1; // mark visiting

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (dfs(neighbor, adj, size, state))
            return 1;
    }

    state[node] = 2; // mark done
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        adj[i] = (int*)malloc(m * sizeof(int));

    // input directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v; // directed
    }

    int* state = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (dfs(i, adj, size, state)) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}