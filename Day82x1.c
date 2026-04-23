#include <stdio.h>
#include <stdlib.h>

// Function to find the Lower Bound
// Returns the index of the first element >= x
int getLowerBound(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n; // Default answer if no element is >= x

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= x) {
            ans = mid;      // Possible answer found
            high = mid - 1; // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Look on the right side
        }
    }
    return ans;
}

// Function to find the Upper Bound
// Returns the index of the first element > x
int getUpperBound(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n; // Default answer if no element is > x

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > x) {
            ans = mid;      // Possible answer found
            high = mid - 1; // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Look on the right side
        }
    }
    return ans;
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    // Read the sorted array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    // Read the target value
    if (scanf("%d", &x) != 1) {
        free(arr);
        return 1;
    }

    // Calculate lower and upper bounds
    int lower_bound_index = getLowerBound(arr, n, x);
    int upper_bound_index = getUpperBound(arr, n, x);

    // Print the results
    printf("%d %d\n", lower_bound_index, upper_bound_index);

    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}