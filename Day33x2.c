#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    char tokens[MAX][20];
    int stack[MAX];
    int top = -1;

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    printf("Enter the tokens:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", tokens[i]);
    }

    for(int i = 0; i < n; i++) {

        if(strcmp(tokens[i], "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }

        else if(strcmp(tokens[i], "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }

        else if(strcmp(tokens[i], "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }

        else if(strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;
        }

        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    printf("Result = %d\n", stack[top]);

    return 0;
}