// main.c

#include <stdio.h>
#include "bubbleSort.h"

int main() {
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array desordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
