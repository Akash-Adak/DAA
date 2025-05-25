#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n, m;

void bfs(int start) {
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int i = 1; i <= adj[u][0]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
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

    printf("BFS traversal: ");
    bfs(start);
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
// output 
// BFS traversal: 0 1 2 3 4

