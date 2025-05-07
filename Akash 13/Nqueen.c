#include<stdio.h>
#include<stdbool.h>
#define v 10

void display(bool board[v][v] ,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j])
			printf("Q ");
			else
			printf(". ");
		}
		printf("\n");
	}	
	printf("\n");
}

bool isSafe(bool board[v][v],int row,int col,int n){
	
	int i=0;
	for( i=0;i<row;i++){
		if(board[i][col]) return false;
	}
	
	int maxLeft=row<col? row:col;
	for( i=0;i<=maxLeft;i++){
		if(board[row-i][col-i]) return false;
	}
	
	int maxRight= row < n-col-1? row : n-col-1;
		for( i=0;i<=maxRight;i++){
		if(board[row-i][col+i]) return false;
	}
	
	return true;
}
int Nqueen(bool board[v][v],int row,int n){
	if(row==n){
		display(board,n);
		return 1;
	}
	int col,count=0;
	for(col=0;col<n;col++){
		if(isSafe(board,row,col, n)){
			board[row][col]=true;
			count+=Nqueen(board,row+1,n);
			board[row][col]=false;;
		}
	}
	return count;
}
int main(){
	int n;
	printf("enter vertex no=");
	scanf("%d",&n);
	bool board[v][v]={false};
 int res=	Nqueen(board,0,n);
 printf("the total combination is = %d",res);
	return 0;
}
