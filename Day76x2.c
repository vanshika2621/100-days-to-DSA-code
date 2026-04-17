#include <stdlib.h>

// pointer-based map
struct Node* keys[101];
struct Node* values[101];
int mapSize = 0;

struct Node* map_get(struct Node* key) {
    for (int i = 0; i < mapSize; i++) {
        if (keys[i] == key) return values[i];
    }
    return NULL;
}

void map_put(struct Node* key, struct Node* value) {
    keys[mapSize] = key;
    values[mapSize] = value;
    mapSize++;
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) return NULL;

    struct Node* found = map_get(node);
    if (found != NULL) return found;

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(
        node->numNeighbors * sizeof(struct Node*)
    );

    map_put(node, clone);

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}