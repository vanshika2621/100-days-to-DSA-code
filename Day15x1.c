#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}
