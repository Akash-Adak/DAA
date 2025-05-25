#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int dp[100][100];

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n, p[100];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions array of size %d: ", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    int result = matrixChainOrder(p, n + 1);
    printf("Minimum number of multiplications: %d\n", result);
    return 0;
}
// Sample Input

// Enter number of matrices: 3
// Enter dimensions array of size 4: 10 20 30 40

// output
// Minimum number of multiplications: 18000