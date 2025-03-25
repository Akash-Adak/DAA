#include <stdio.h>
#include <stdbool.h>
#define N 10

void display(bool board[N][N],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("Q ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(bool board[N][N], int row, int col,int n) {
    // verticaly
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    
    int maxLeft = (row < col) ? row : col;
    for (int i = 1; i <= maxLeft; i++) {
        if (board[row - i][col - i]) {
            return false;
        }
    }
    int maxRight = (row < (n - col - 1)) ? row : (n - col - 1);
    for (int i = 1; i <= maxRight; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }
    
    return true;
}
int queens(bool board[N][N], int row,int n) {
    if (row == n) {
        display(board,n);
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col,n)) {
            board[row][col] = true;
            count += queens(board, row + 1,n);
            board[row][col] = false;
        }
    }

    return count;
}

int main() {
    int n;
    printf("enter no=");
    scanf("%d",&n);
    bool board[N][N] = {false};
    printf("Total solutions: %d\n", queens(board, 0,n));
    return 0;
}
