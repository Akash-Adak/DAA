
#include <stdio.h>
#include <limits.h>
 
#define MAX 100

int findMinVertex(int dist[], int visited[], int n) {
    int min = INT_MAX, minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int graph[MAX][MAX], int visited[], int dist[], int n, int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(dist, visited, n);
        if (u == -1) break; 
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int graph[MAX][MAX] = {0}; 
    int visited[MAX], dist[MAX];
    int e, vertices, source, weight;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (format: u v weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d%d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; 
    }

    printf("Enter start vertex: ");
    scanf("%d", &source);

    dijkstra(graph, visited, dist, vertices, source);

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> %d: Unreachable\n", source, i);
        else
            printf("%d -> %d: %d\n", source, i, dist[i]);
    }

    return 0;
}



