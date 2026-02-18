#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* answer = (int*)malloc(numsSize * sizeof(int));

    // Step 1: Store left products
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with right products
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return answer;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = productExceptSelf(nums, n, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
