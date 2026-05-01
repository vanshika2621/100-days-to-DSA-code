#include <stdio.h>

int canShip(int* weights, int n, int days, int capacity) {
    int currentWeight = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (weights[i] > capacity) return 0;

        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
        } else {
            requiredDays++;
            currentWeight = weights[i];
        }
    }

    return requiredDays <= days;
}

int shipWithinDays(int* weights, int n, int days) {
    int max = weights[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > max) max = weights[i];
        sum += weights[i];
    }

    int low = max, high = sum, answer = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, n, days, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, days;
    scanf("%d %d", &n, &days);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int result = shipWithinDays(weights, n, days);
    printf("%d\n", result);

    return 0;
}