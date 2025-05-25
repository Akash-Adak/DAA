#include <stdio.h>
#define INF 1000000

void bellmanFord(int V, int E, int edges[][3], int src, int dist[]) {
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected\n");
            return;
        }
    }
    
    printf("the sortes distance from source is:\n");
    for (int i = 0; i < V; i++)
        printf("from %d to %d  distance is %d\n", src, i, dist[i]);
}

int main() {
    int V, E;
    printf("enter vertex and edges:");
    scanf("%d %d", &V, &E);
        
    printf("enter edges if form of source destination weight\n");
    int edges[E][3];
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

        printf("enter source:");
    int src;
    scanf("%d", &src);

    int dist[V];
    bellmanFord(V, E, edges, src, dist);

    return 0;
}
// 🔢 Sample Input:

// enter vertex and edges: 5 8
// enter edges if form of source destination weight
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3
// enter source: 0
// ✅ Output:

// the sortes distance from source is:
// from 0 to 0  distance is 0
// from 0 to 1  distance is -1
// from 0 to 2  distance is 2
// from 0 to 3  distance is -2
// from 0 to 4  distance is 1