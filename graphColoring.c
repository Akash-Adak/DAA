#include<stdio.h>
int color[100];
void next_cal(int k,int graph[][100]){
    color[k]=1;
    for(int i=0;i<k;i++){
        if(graph[i][k]!=0 && color[k]==color[i]){
            color[k]=color[i]+1;
        }
    }
}
void graphColoring(int graph[][100],int v){
   for(int i=0;i<v;i++){
    next_cal(i,graph);
   }
}
int main() {
    int V;
    printf("enter no of vertices:");
    scanf("%d", &V);

    int graph[100][100];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // int color[V];
    graphColoring(graph, V);
     printf("colors are:\n");
     for(int i=0;i<V;i++){
        printf("%d ",color[i]);
     }
    return 0;
}

// Sample Input:

// enter no of vertices: 4
// 0 1 1 0
// 1 0 1 1
// 1 1 0 1
// 0 1 1 0


// Expected Output:

// colors are:
// 1 2 3 2 