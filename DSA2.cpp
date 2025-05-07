#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sequential Search Function
void linearSearch(int data[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (data[i] == target) {
            printf("-> Found %d at position %d\n", target, i);
            return;
        }
    }
    printf("-> Value %d not found in the array\n", target);
}

int main() {
    const int N = 5;
    int numbers[N];
    int searchItem;

    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Capture time before processing
    clock_t cpu_start = clock();
    time_t wall_start = time(NULL);

    // Populate array with random numbers between 1 and 1000
    printf(":: Generated Values:\n");
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 1000 + 1;
        printf("Index %d -> %d\n", i, numbers[i]);
    }

    // Choose a random item from the array to search
    searchItem = numbers[rand() % N];
    printf("\n:: Looking for value: %d\n", searchItem);

    // Call search
    linearSearch(numbers, N, searchItem);

    // Capture time after processing
    clock_t cpu_end = clock();
    time_t wall_end = time(NULL);

    // Compute durations
    double cpu_duration = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC;
    double wall_duration = difftime(wall_end, wall_start);

    // Show timing results
    printf("\n:: Time Summary:\n");
    printf("Started at: %s", ctime(&wall_start));
    printf("Finished at: %s", ctime(&wall_end));
    printf("CPU Time Used: %.6f seconds\n", cpu_duration);
    printf("Elapsed (Wall Clock) Time: %.2f seconds\n", wall_duration);

    return 0;
}

