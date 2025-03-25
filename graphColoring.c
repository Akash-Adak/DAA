#include <stdio.h>
#include <stdbool.h>

#define V 10  

int color[V];

void graphColoring(int graph[V][V], int k) {
    color[k] = 1;

    for (int u = 0; u < k; u++) {
        if (graph[u][k] != 0 && color[k] == color[u]) {
            color[k] = color[u] + 1;
        }
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    int graph[V][V];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    color[0] = 1;

    for (int i = 1; i < v; i++) {
        graphColoring(graph, i);
    }

    printf("Vertex Coloring:\n");
    for (int i = 0; i < v; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }

    return 0;
}
