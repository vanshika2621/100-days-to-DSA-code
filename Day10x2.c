#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int nums1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &m);
    int nums2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);

    int freq[1001] = {0};   // assuming values 0–1000

    for (int i = 0; i < n; i++)
        freq[nums1[i]]++;

    for (int i = 0; i < m; i++) {
        if (freq[nums2[i]] > 0) {
            printf("%d ", nums2[i]);
            freq[nums2[i]]--;
        }
    }

    return 0;
}
