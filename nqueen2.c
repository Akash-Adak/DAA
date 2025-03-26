#include<stdio.h>
#include<math.h>
#define max 10

int board[max] ,n,c=0;
int place(int k ,int i){
    int j ;
    for(j=0;j<k;j++){
        if(board[j]==i||abs(board[j]-i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}
void printboard(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(board[i]==j){
                printf(" Q ");
            }
            else{
                printf(" X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void NQ(int k){
    int i;
    for(i=0;i<n;i++){
        if(place(k,i)){
            board[k]=i;
            if(k==n-1){
                printboard();
                c++;
            }
            else{
                NQ(k+1);
            }
        }
    }
}
int main(){
    printf("enter number of queens : ");
    scanf("%d",&n);
    if(n>max){
        printf("maximum supported value is : %d\n",max);
        return 1;
    }
    NQ(0);
    printf("total numbers if possibilioties: %d\n",c);
    return 0;
}
