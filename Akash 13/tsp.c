#include <stdio.h>
#include <limits.h>

int tsp(int m[][100], int path[], int pos, int visited[], int cost, int n, int best_path[], int *min_cost) {
	int i;
    if (pos == n) {
        if (m[path[pos - 1]][path[0]] > 0) {
            cost += m[path[pos - 1]][path[0]];
            if (cost < *min_cost) {
                *min_cost = cost;
                for ( i = 0; i < n; i++) {
                    best_path[i] = path[i];
                }
                best_path[n] = path[0];
            }
            return cost;
        }
        return INT_MAX;
    }

    int current_min_cost = INT_MAX;
    for (i = 0; i < n; i++) {
        if (!visited[i] && m[path[pos - 1]][i] > 0) {
            visited[i] = 1;
            path[pos] = i;
            int curr_cost = tsp(m, path, pos + 1, visited, cost + m[path[pos - 1]][i], n, best_path, min_cost);
            if (curr_cost < current_min_cost) {
                current_min_cost = curr_cost;
            }
            visited[i] = 0;
        }
    }
    return current_min_cost;
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    int m[100][100], i, j;
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    
    int path[100];
    int visited[100] = {0};
    int best_path[100];
    int min_cost = INT_MAX;
    path[0] = 0;
    visited[0] = 1;

    tsp(m, path, 1, visited, 0, n, best_path, &min_cost);
    
    printf("The minimum cost is %d\n", min_cost);
    printf("The shortest path is: ");
    for (i = 0; i <= n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\npath is=");
     for (i = 1; i <= sizeof(path); i++) {
     	if(path[i]!=0)
        printf("%d ", path[i]);
    }
    printf("\n");
    
    return 0;
}

