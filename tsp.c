#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 999999

int n;
int dist[MAX][MAX];
int visited[MAX];
int minCost = INF;
int path[MAX], bestPath[MAX];

void tsp(int level, int currentCity, int cost) {
    if (level == n) {
        if (dist[currentCity][0] != 0) {
            int totalCost = cost + dist[currentCity][0];
            if (totalCost < minCost) {
                minCost = totalCost;
                for (int i = 0; i < n; i++) {
                    bestPath[i] = path[i];
                }
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[currentCity][i] != 0) {
            visited[i] = 1;
            path[level] = i;
            tsp(level + 1, i, cost + dist[currentCity][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    visited[0] = 1;
    path[0] = 0;

    tsp(1, 0, 0);

    printf("Minimum tour cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", bestPath[i]);
    }
    printf("0\n"); // return to start

    return 0;
}
// input

// Enter number of cities: 4
// Enter cost matrix (4 x 4):
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0

//output 

// Minimum tour cost: 80
// Path: 0 -> 1 -> 3 -> 2 -> 0

