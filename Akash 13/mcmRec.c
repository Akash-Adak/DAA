#include <stdio.h>
#include <limits.h>

int mcm(int arr[], int i, int j, int dp[][100]) {
    if (i + 1 == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int res = INT_MAX,k;
    for ( k = i + 1; k < j; k++) {
        int curr = mcm(arr, i, k, dp) + mcm(arr, k, j, dp) + arr[i] * arr[k] * arr[j];
        res = (res > curr) ? curr : res;
    }
    dp[i][j] = res;
    return res;
}

int main() {
    int v,i,j;
    printf("Enter size of the array dimensions: ");
    scanf("%d", &v);
    int arr[v];
    printf("Enter matrix:\n");
    for ( i = 0; i < v; i++) {
        scanf("%d", &arr[i]);
    }
    int dp[100][100];
    for ( i = 0; i < 100; i++)
        for ( j = 0; j < 100; j++)
            dp[i][j] = -1;

    int res = mcm(arr, 0, v - 1, dp);
    printf("The minimum cost is = %d\n", res);
    return 0;
}

