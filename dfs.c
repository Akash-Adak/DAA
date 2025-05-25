#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int i = 1; i <= adj[u][0]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int u, v, start;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][++adj[u][0]] = v;
        adj[v][++adj[v][0]] = u;
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);
    printf("\n");
    
    return 0;
}
// input 

// Enter number of vertices and edges: 5 6
// 0 1
// 0 2
// 1 3
// 1 4
// 2 4
// 3 4
// Enter starting node: 0

//output
// DFS traversal: 0 1 3 4 2
