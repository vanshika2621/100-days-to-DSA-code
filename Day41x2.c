#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    // Count frequency of tasks
    for(int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count tasks having maximum frequency
    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq)
            maxCount++;
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;

    int minIntervals = partCount * partLength + maxCount;

    return max(size, minIntervals);
}

int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks)/sizeof(tasks[0]);

    int result = leastInterval(tasks, size, n);

    printf("Minimum CPU intervals: %d\n", result);

    return 0;
}