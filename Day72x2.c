#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};  // For 'a' to 'z'

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        freq[index]++;
    }

    // If no repeated character found
    printf("-1\n");

    return 0;
}