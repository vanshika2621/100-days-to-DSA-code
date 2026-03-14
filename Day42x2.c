#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[50000];
    int size;
} MedianFinder;

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->size = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    obj->arr[obj->size++] = num;
    qsort(obj->arr, obj->size, sizeof(int), cmp);
}

double medianFinderFindMedian(MedianFinder* obj) {
    int n = obj->size;

    if (n % 2 == 1)
        return obj->arr[n/2];

    return (obj->arr[n/2 - 1] + obj->arr[n/2]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

int main() {
    MedianFinder* mf = medianFinderCreate();

    medianFinderAddNum(mf, 1);
    medianFinderAddNum(mf, 2);
    printf("%.1f\n", medianFinderFindMedian(mf));

    medianFinderAddNum(mf, 3);
    printf("%.1f\n", medianFinderFindMedian(mf));

    medianFinderFree(mf);
    return 0;
}