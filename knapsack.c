#include <stdio.h>

void sortItems(int n, int weight[], int value[], float ratio[]) {
    for (int i = 0; i < n; i++)
        ratio[i] = (float)value[i] / weight[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;

                int tempW = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempW;

                int tempV = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempV;
            }
        }
    }
}

float fractionalKnapsack(int n, int capacity, int weight[], int value[]) {
    float ratio[n];
    sortItems(n, weight, value, ratio);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("enter the number of items: ");
    scanf("%d", &n);
    printf("enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int weight[n], value[n];
    printf("enter the weight of each item: ");
    for (int i = 0; i<n ; i++)  
        scanf("%d", &weight[i]);
    
    printf("enter the value of each item: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    float maxValue = fractionalKnapsack(n, capacity, weight, value);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}
// Example Input

// enter the number of items: 3
// enter the capacity of the knapsack: 50
// enter the weight of each item: 10 20 30
// enter the value of each item: 60 100 120

// Total value = 60 + 100 + 80 = 240

// Output

// Maximum value: 240.00