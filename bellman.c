#include <stdio.h>

#define INF 99999 
#define MAX 100    

void bellmanFord(int graph[MAX][MAX], int V, int source) {
    int distance[V];
    for (int i = 0; i < V; i++)
        distance[i] = INF;
    distance[source] = 0;

    for (int k = 0; k < V - 1; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != INF && distance[i] != INF && distance[i] + graph[i][j] < distance[j]) {
                    distance[j] = distance[i] + graph[i][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != INF && distance[i] != INF && distance[i] + graph[i][j] < distance[j]) {
                printf("Graph contains a negative weight cycle!\n");
                return;
            }
        }
    }

    printf("\nVertex\tDistance from Source (%d)\n", source);
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, distance[i]);
}

int main() {
    int V, source;
    int graph[MAX][MAX];


    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, V, source);

    return 0;
}
