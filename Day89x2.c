#include <stdio.h>

// Check if we can ship within given days using capacity
int canShip(int* weights, int n, int days, int capacity) {
    int currentLoad = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        // If single package exceeds capacity
        if (weights[i] > capacity)
            return 0;

        if (currentLoad + weights[i] <= capacity) {
            currentLoad += weights[i];
        } else {
            requiredDays++;
            currentLoad = weights[i];

            if (requiredDays > days)
                return 0;
        }
    }

    return 1;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int max = 0, sum = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > max)
            max = weights[i];
        sum += weights[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1; // try smaller capacity
        } else {
            low = mid + 1; // increase capacity
        }
    }

    return ans;
}