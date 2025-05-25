#include <stdio.h>

#define INF 99999
#define V 100

void floydWarshall(int graph[][V], int n) {
    int dist[V][V];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int graph[V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int matrix[V][V];
    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    floydWarshall(matrix, n);
    return 0;
}
// ✅ Sample Input

// Enter number of vertices: 4
// Enter adjacency matrix (use 99999 for INF):
// 0 5 99999 10
// 99999 0 3 99999
// 99999 99999 0 1
// 99999 99999 99999 0
// ✅ Expected Output

// Shortest distances between every pair of vertices:
//   0   5   8   9
// INF   0   3   4
// INF INF   0   1
// INF INF INF   0