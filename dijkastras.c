#include <stdio.h>
#define INF 1000000
#define MAX 100

int adj[MAX][MAX];
int weight[MAX][MAX];
int dist[MAX], visited[MAX];
int n, m;

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int i = 0; i < adj[u][0]; i++) {
            int v = adj[u][i + 1];
            if (!visited[v] && dist[u] + weight[u][v] < dist[v]) {
                dist[v] = dist[u] + weight[u][v];
            }
        }
    }
}

int main() {
    int u, v, w, start;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) adj[i][0] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][0]++;
        adj[u][adj[u][0]] = v;
        weight[u][v] = w;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
// ✅ Example Input:

// Enter number of vertices and edges: 5 6
// Enter edges (u v w):
// 0 1 10
// 0 4 5
// 1 2 1
// 2 3 4
// 4 1 3
// 4 2 9
// Enter start node: 0
// ✅ Output:

// Shortest distances from node 0:
// 0 -> 0
// 1 -> 8
// 2 -> 9
// 3 -> 13
// 4 -> 5