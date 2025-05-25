#include <stdio.h>
#include <math.h>

#define MAX 10

int board[MAX], n;

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (board[j] == i || abs(board[j] - i) == abs(j - k)) {
            return 0; // Conflict
        }
    }
    return 1; // Safe placement
}

void NQ(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            board[k] = i; // Place queen
            if (k == n) { // If all queens are placed, print solution
                for (int j = 1; j <= n; j++) {
                    printf("%d ", board[j]);
                }
                printf("\n");
            } else {
                NQ(k + 1, n); // Recur to place the next queen
            }
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Maximum supported value is %d\n", MAX);
        return 1;
    }
    NQ(1, n); // Start from the first row
    return 0;
}