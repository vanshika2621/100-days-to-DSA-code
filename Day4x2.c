#include <stdio.h>

int removeElement(int nums[], int n, int val) {
    int k = 0;   // points to where next valid element goes

    for(int i = 0; i < n; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n, val;
    int nums[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
