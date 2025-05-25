#include <stdio.h>
#define MAX 100
#define INF 1000000

int edges[MAX][3]; // edges[i][0] = u, edges[i][1] = v, edges[i][2] = weight
int parent[MAX];
int n, m;

void sortEdges() {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i][2] > edges[j][2]) {
                int temp0 = edges[i][0], temp1 = edges[i][1], temp2 = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp0;
                edges[j][1] = temp1;
                edges[j][2] = temp2;
            }
        }
    }
}

int find(int u) {
    while (u != parent[u])
        u = parent[u];
    return u;
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
        parent[rootV] = rootU;
}

void kruskal() {
    for (int i = 0; i < n; i++) parent[i] = i;
    sortEdges();

    int total = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            total += w;
            unionSet(u, v);
        }
    }
    printf("Total cost: %d\n", total);
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskal();

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
// ✅ Sample Output

// Edges in MST:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Total cost: 16