int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    
    while (low <= high) {
        // Prevent potential overflow that can happen with (low + high) / 2
        int mid = low + (high - low) / 2; 
        
        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            low = mid + 1; // Target must be in the right half
        } else {
            high = mid - 1; // Target must be in the left half
        }
    }
    
    // If the loop finishes and target isn't found, 'low' will be pointing 
    // to the correct insertion index.
    return low;
}