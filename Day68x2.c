#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

char* alienOrder(char** words, int wordsSize) {
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // Mark characters present
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < wordsSize - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Prefix invalid case
        if (!found && len1 > len2) {
            char* empty = (char*)malloc(1);
            empty[0] = '\0';
            return empty;
        }
    }

    // Queue for BFS
    int queue[MAX];
    int front = 0, rear = 0;

    // Push all 0 indegree nodes
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char* result = (char*)malloc(27);
    int index = 0;

    while (front < rear) {
        int u = queue[front++];
        result[index++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    result[index] = '\0';

    // Count total unique chars
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    // Cycle check
    if (index != total) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    return result;
}