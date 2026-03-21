#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expand(char* s, int left, int right, int* start, int* maxLen) {
    while (left >= 0 && s[right] && s[left] == s[right]) {
        if (right - left + 1 > *maxLen) {
            *maxLen = right - left + 1;
            *start = left;
        }
        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        expand(s, i, i, &start, &maxLen);     // odd length
        expand(s, i, i + 1, &start, &maxLen); // even length
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}