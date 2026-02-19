int maxSubarraySumCircular(int* nums, int numsSize) {
    int total_sum = 0;
    int max_sum = nums[0], curr_max = 0;
    int min_sum = nums[0], curr_min = 0;

    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];

        // Standard Kadane for max
        curr_max = (curr_max + num > num) ? curr_max + num : num;
        max_sum = (max_sum > curr_max) ? max_sum : curr_max;

        // Kadane for min
        curr_min = (curr_min + num < num) ? curr_min + num : num;
        min_sum = (min_sum < curr_min) ? min_sum : curr_min;

        total_sum += num;
    }

    // If all numbers are negative
    if (max_sum < 0)
        return max_sum;

    // Return max of normal and circular
    return (max_sum > total_sum - min_sum) ? 
            max_sum : total_sum - min_sum;
}
