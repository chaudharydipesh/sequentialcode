#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[100];
    int n, key, i;
    int found = 0;

    clock_t t;
    double timeTaken;

    printf("enter the number of elements"); // array size
    scanf("%d", &n);

    if (n > 100 || n <= 0) { // checking if the size is valid or not
        printf("invalid size");
        return 0;
    }

    srand(time(NULL)); // seeding random number generator

    printf("array"); // generating random elements in array
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n enter number to search"); // number to be searched
    scanf("%d", &key);

    t = clock(); // initial time

    for (i = 0; i < n; i++) { // sequential search
        if (arr[i] == key) {
            printf("Number %d found at index %d\n", key, i);
            found = 1;
        }
    }
t=clock() - t; //total time calculation
    timeTaken = (double)(clock() - t) / CLOCKS_PER_SEC;

    if (found==0) {
        printf("number not found\n");
    }

    printf("time taken %lf seconds\n", timeTaken);

    return 0;
}
