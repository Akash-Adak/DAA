#include <stdio.h>
#include <stdbool.h>
#define N 4 

void display(bool board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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

bool isSafe(bool board[N][N], int row, int col) {
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
    
    int maxRight = (row < (N - col - 1)) ? row : (N - col - 1);
    for (int i = 1; i <= maxRight; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }
    
    return true;
}

int queens(bool board[N][N], int row) {
    if (row == N) {
        display(board);
        return 1;
    }

    int count = 0;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            count += queens(board, row + 1);
            board[row][col] = false;
        }
    }

    return count;
}

int main() {
    bool board[N][N] = {false};
    printf("Total solutions: %d\n", queens(board, 0));
    return 0;
}
