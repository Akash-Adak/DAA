#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int edges[MAX][3];
int parent[MAX];
int rank[MAX];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void kruskal(int v,int e){
	int i,j,k;
	 for ( i = 0; i < v; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for ( i = 0; i < e - 1; i++) {
        for ( j = 0; j < e - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                for ( k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }

    int mstWeight = 0;
    printf("Edges in MST:\n");
    for ( i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            printf("%d - %d: %d\n", u, v, w);
            mstWeight += w;
            unionSets(u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
	
}
int main() {
    int v, e,i,j;
    printf("enter no of vertices:");
    scanf("%d", &v);

    printf("Enter no of edges:");
    scanf("%d", &e);

    printf("Enter the edges (u, v, weight):\n");
    for ( i = 0; i < e; i++)
        for ( j = 0; j < 3; j++)
            scanf("%d", &edges[i][j]);

   
   kruskal(v,e);

    return 0;
}
