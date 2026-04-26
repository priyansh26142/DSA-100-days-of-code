#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    // Allocate max possible space (m for safety)
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;  // remove for directed graph
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}