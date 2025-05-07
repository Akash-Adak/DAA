#include<stdio.h>
#define m 100

int adj[m][m], visited[m], q[m];
int front = 0, rear = -1, n;

void enqueue(int x) {
    if (rear == m - 1) return;
    q[++rear] = x;
}

int dequeue() {
    if (front > rear) return -1;
    return q[front++];
}

void bfs(int start) {
    int i;
    visited[start] = 1;
    enqueue(start);              
    while (front <= rear) {
        int curr = dequeue();
        if (curr == -1) break;
        printf("%d ", curr);
        for (i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int e, i, u, v, start,j;     
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);      
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("BFS is: ");
    bfs(start);
    return 0;
}
