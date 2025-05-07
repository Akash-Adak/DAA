#include<stdio.h>

void knapsack(int weight[], int value[], int n, int w) {
    int i, j;
    float ratio[n];
    for (i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j + 1] > ratio[j]) {
                ratio[j] = ratio[j] + ratio[j + 1] - (ratio[j + 1] = ratio[j]);
                weight[j] = weight[j] + weight[j + 1] - (weight[j + 1] = weight[j]);
                value[j] = value[j] + value[j + 1] - (value[j + 1] = value[j]);
            }
        }
    }

    int cW = 0;
	 float max= 0;

    for (i = 0; i < n; i++) {
        if (cW + weight[i] <= w) {
            cW += weight[i];
            max += value[i];
        } else {
            int re = w - cW;
            max += ratio[i] * re;
            break;
        }
    }

    printf("maximum value= %d", max);
}

int main() {
    int n, w, i;
    printf("enter no of element:");
    scanf("%d", &n);
    int weight[n];
    int value[n];

    printf("enter container weight:");
    scanf("%d", &w);
    printf("enter the weight :\n:");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    printf("enter the value :\n:");
    for (i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    knapsack(weight, value, n, w);
}
