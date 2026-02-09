#include <stdio.h>

void reverseString(char s[], int n) {
    int i = 0, j = n - 1;
    char temp;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char s[] = {'h','e','l','l','o'};
    int n = sizeof(s) / sizeof(s[0]);

    reverseString(s, n);

    for (int i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}
