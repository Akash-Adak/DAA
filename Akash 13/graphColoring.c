#include<stdio.h>
#define v 10
int color[v];
void graphColor(int g[v][v],int n,int k){
	color[k]=1;
	int i=0;
	for(i=0;i<k;i++){\-0                       
		if(g[i][k]!=0 && color[k]==color[i]){
			color[k]=color[i]+1;
		}
	}
}
int main(){
	int n;
	printf("enter vertex no=");
	scanf("%d",&n);
	int g[v][v];
	int i,j;
	printf("enter adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	 
	for(i=0;i<n;i++){
		graphColor(g,n,i);
	}
	
	for(i=0;i<n;i++){
		printf("\ncolor for %d vertex is = %d",i,color[i]);
	}
	
	return 0;
}
