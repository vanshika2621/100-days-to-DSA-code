#include <stdio.h>

int orangesRotting(int grid[10][10], int m, int n) {
    int queue[100][2];
    int front = 0, rear = 0;
    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    fresh--;
                }
            }
        }
        minutes++;
    }

    if (fresh > 0) return -1;
    return minutes;
}

int main() {
    int m, n;
    int grid[10][10];

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);
    printf("%d\n", result);

    return 0;
}