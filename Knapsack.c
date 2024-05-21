#include <stdio.h>
#define MAX_ITEMS 100
struct Item {
    int weight;
    int profit;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortByProfitPerWeight(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double)items[i].profit / items[i].weight;
            double ratio2 = (double)items[j].profit / items[j].weight;
            if (ratio1 < ratio2) {
                swap(&items[i], &items[j]);
            }
        }
    }
}
void knapsack(struct Item items[], int n, int capacity, int option) {
    switch (option) {
        case 1: // Largest Profit
            sortByProfitPerWeight(items, n);
            break;
        case 2: 
            break; 
        case 3: // Largest Profit to Weight Ratio
            sortByProfitPerWeight(items, n);
            break;
        default:
            printf("Invalid option\n");
            return;
    }
    int totalWeight = 0;
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remainingWeight = capacity - totalWeight;
            totalProfit += (double)remainingWeight * items[i].profit / items[i].weight;
            break;
        }
    }
    printf("Total profit: %.2lf\n", totalProfit);
}
int main() {
    struct Item items[MAX_ITEMS];
    int n, capacity, option;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and profits of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    printf("Select option:\n");
    printf("1. Largest Profit\n");
    printf("2. Smallest Weight\n");
    printf("3. Largest Profit to Weight Ratio\n");
    scanf("%d", &option);
    knapsack(items, n, capacity, option);
    return 0;
}
