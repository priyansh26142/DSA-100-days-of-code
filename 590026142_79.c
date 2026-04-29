#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;

// Adjacency matrix
int graph[MAX][MAX];

// Distance array
int dist[MAX];

// Visited array
int visited[MAX];

// Function to find node with minimum distance
int findMin() {
    int min = INT_MAX, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra function
void dijkstra(int source) {
    // Initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = findMin();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove this line if graph is directed
    }

    int source;
    scanf("%d", &source);

    dijkstra(source);

    // Output
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}