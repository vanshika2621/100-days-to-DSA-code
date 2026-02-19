#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = 1000000;
    int min_left = left, min_right = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements whose sum is closest to zero are: %d and %d\n",
           arr[min_left], arr[min_right]);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    findClosestToZero(arr, n);

    return 0;
}
