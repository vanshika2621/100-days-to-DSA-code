#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays (since constraints are not specified)
typedef struct {
    int key;
    int value;
} Hash;

Hash hash[MAX];
int size = 0;

// Find key in hash
int find(int key) {
    for (int i = 0; i < size; i++) {
        if (hash[i].key == key)
            return hash[i].value;
    }
    return -1;
}

// Insert key-value pair
void insert(int key, int value) {
    hash[size].key = key;
    hash[size].value = value;
    size++;
}

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0)
            max_len = i + 1;

        // Case 2: sum seen before
        int prev = find(sum);
        if (prev != -1) {
            int len = i - prev;
            if (len > max_len)
                max_len = len;
        } else {
            insert(sum, i);
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d\n", maxLen(arr, n));

    return 0;
}