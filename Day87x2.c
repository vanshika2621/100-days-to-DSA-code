int canEat(int* piles, int pilesSize, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        // ceil(piles[i] / k)
        hours += (piles[i] + k - 1) / k;

        if (hours > h) return 0; // early stop
    }

    return 1;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;

    // find max pile
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEat(piles, pilesSize, h, mid)) {
            ans = mid;
            right = mid - 1; // try smaller k
        } else {
            left = mid + 1;  // need bigger k
        }
    }

    return ans;
}