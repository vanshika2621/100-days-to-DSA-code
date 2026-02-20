#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Simple hash map using array (works if sum range is manageable)
int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    int prefixSum = 0;

    // Using large array as hash table
    int *freq = (int*)calloc(2 * MAX + 1, sizeof(int));

    // Offset to handle negative sums
    int offset = MAX;

    freq[offset] = 1;  // prefix sum 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + offset] > 0) {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    free(freq);
    return count;
}

int main() {
    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of zero-sum subarrays: %d\n", result);

    return 0;
}