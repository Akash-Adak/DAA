#include<stdio.h>
#define m 100
#define inf 99999

void floyed_warsal(int g[m][m],int v){
	int dist[m][m];
	int i,j,k;
		for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		dist[i][j]=g[i][j];
		
	for(k=0;k<v;k++)
		for(i=0;i<v;i++)
			for(j=0;j<v;j++)
				if(dist[i][k]!=inf && dist[k][j]!=inf && dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
		
	 printf("\nShortest distance matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (dist[i][j] == inf)
                printf("%7s", "inf");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n"); 
    }
	
}
int main(){
	int v,i,j;
	printf("enter the vertices no:");
	scanf("%d",&v);
	int g[m][m];
	printf("enter the adjacency matrix(enter 99999 for infinity):\n");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&g[i][j]);
	
	floyed_warsal(g,v);
	return 0;
}
