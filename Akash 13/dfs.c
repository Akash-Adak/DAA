#include<stdio.h>
#define m 100
int adj[m][m], visited[m],n;

void dfs(int start) {

    visited[start] = 1;
    printf("%d ", start);             
        for (int i = 0; i < n; i++) {
            if (adj[start][i] && !visited[i]) {
               dfs(i);                                                  
            }
        }
}

int main() {
    int e, u, v, start,j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("DFS is: ");
    dfs(start);
    return 0;
}
