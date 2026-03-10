#include <stdio.h>

#define MAX 10000

void maxSlidingWindow(int nums[], int n, int k) {
    int dq[MAX];     // deque storing indices
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove indices out of window
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        // Insert current index
        dq[++rear] = i;

        // Print max when window is valid
        if (i >= k - 1)
            printf("%d ", nums[dq[front]]);
    }
}

int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 3;

    maxSlidingWindow(nums, n, k);

    return 0;
}