#include <stdio.h>
#include <time.h>

struct Item {
    int value, weight;
    float ratio;
};

// Function to sort items in decreasing order of ratio
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    float capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    clock_t start, end;
    start = clock(); // start timer

    sortItems(items, n);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * (capacity / items[i].weight);
            break;
        }
    }

    end = clock(); // end timer
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMaximum value in knapsack = %.2f", totalValue);
    printf("\nExecution time: %.6f seconds\n", time_taken);

    return 0;
}