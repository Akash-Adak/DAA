#include <stdio.h>
#include <limits.h>

#define INF 99999

int minKey(int key[], int visited[], int n) {
    int min = INF, min_index,v;

    for ( v = 0; v < n; v++)
        if (!visited[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void prim(int graph[10][10], int n) {
    int parent[n];
    int key[n];
    int visited[n];
   int i,count,v;
    for ( i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for ( count = 0; count < n - 1; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        for ( v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for ( i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n,i,j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);g g                                                                                                                        


    int graph[10][10];

    printf("Enter the adjacency matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prim(graph, n);

    return 0;
}
