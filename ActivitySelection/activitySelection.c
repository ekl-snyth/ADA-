#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort activities by finish time using simple Bubble Sort
void sortActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                swap(&finish[j], &finish[j + 1]);
                swap(&start[j], &start[j + 1]);
            }
        }
    }
}

// Function to perform Activity Selection
void activitySelection(int start[], int finish[], int n) {
    // Sort activities by finish time
    sortActivities(start, finish, n);

    printf("Sorted Activities by finish time:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: Start = %d, Finish = %d\n", i + 1, start[i], finish[i]);
    }

    printf("\nSelected Activities are:\n");

    int i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i = j;
        }
    }
}

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times of activities:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times of activities:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &finish[i]);

    printf("\n--- Activity Selection using Greedy Method ---\n");
    activitySelection(start, finish, n);

    return 0;
}
