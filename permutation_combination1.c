#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end) {
    int i;
    if (start == end) {
        for (i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (i = start; i <= end; i++) {
            swap((arr + start), (arr + i));
            permute(arr, start + 1, end);
            swap((arr + start), (arr + i)); // backtrack
        }
    }
}

void combine(int arr[], int data[], int start, int end, int index, int r) {
    int i;
    if (index == r) {
        for (i = 0; i < r; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combine(arr, data, i + 1, end, index + 1, r);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = 2; // number of elements to choose

    printf("Permutations of the array:\n");
    permute(arr, 0, n - 1);

    printf("\nCombinations of the array:\n");
    int data[r];
    combine(arr, data, 0, n - 1, 0, r);

    return 0;
}