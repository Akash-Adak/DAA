#include<stdio.h>
#define m 100
#define inf 99999

void bellman_ford(int g[m][m], int v, int source) {
    int i, j,k;
    int dist[v];

    for (i = 0; i < v; i++) {
        dist[i] = inf;
    }
    dist[source] = 0;

    for ( k = 1; k <= v - 1; k++) {
        for ( i = 0; i < v; i++) {
            for ( j = 0; j < v; j++) { 
                if (g[i][j] != inf && dist[i] != inf && dist[i] + g[i][j] < dist[j]) {
                    dist[j] = dist[i] + g[i][j];
                }
            }
        }
    }
    printf("The sorted distances: ");
    for (i = 0; i < v; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int v, i, j, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int g[m][m];

    printf("Enter the adjacency matrix (enter 99999 for infinity):\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellman_ford(g, v, source);

    return 0;
}

