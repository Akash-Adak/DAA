#include <stdio.h>
#define INF 1000000
#define MAX 100

int adj[MAX][MAX];
int weight[MAX][MAX];
int visited[MAX], minEdge[MAX], parent[MAX];
int n, m;

void prim(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        minEdge[i] = INF;
        parent[i] = -1;
    }

    minEdge[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minEdge[i] < min) {
                min = minEdge[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int i = 0; i < adj[u][0]; i++) {
            int v = adj[u][i + 1];
            if (!visited[v] && weight[u][v] < minEdge[v]) {
                minEdge[v] = weight[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            total += weight[i][parent[i]];
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, weight[i][parent[i]]);
        }
    }
    printf("Total cost: %d\n", total);
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

        adj[v][0]++;
        adj[v][adj[v][0]] = u;
        weight[v][u] = w;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    prim(start);

    return 0;
}

// ✅ Input Format

// Enter number of vertices and edges: 5 7
// Enter edges (u v w):
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
// 3 4 9
// Enter start node: 0
// ✅ Sample Output

// Edges in MST:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Total cost: 16