int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        // If already sorted
        if (nums[left] < nums[right])
            return nums[left];

        int mid = left + (right - left) / 2;

        // Decide which side to go
        if (nums[mid] >= nums[left]) {
            // Left part sorted → min in right
            left = mid + 1;
        } else {
            // Min is in left part (including mid)
            right = mid;
        }
    }

    return nums[left];
}