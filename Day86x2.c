int mySqrt(int x) {
    if (x < 2) return x;  // handles 0 and 1

    int left = 1, right = x / 2;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            ans = mid;        // store valid answer
            left = mid + 1;   // try bigger
        } else {
            right = mid - 1;  // go smaller
        }
    }

    return ans;
}