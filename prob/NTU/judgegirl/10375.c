#include <stdio.h>
#include <stddef.h>
#define MAX_PTR_ARR_SIZE 1000 
int countIntersections(int* ptrArray[]) {
    int cnt = 0;
    for(int i = 0; i < MAX_PTR_ARR_SIZE; ++i) {
        if(ptrArray[i] == NULL) break;
        for(int j = 0; j < i; ++j) {
            cnt += (ptrArray[j] - ptrArray[i] > 0);
        } 
    }
    return cnt;
}

#define MAX_ARR_SIZE 10000
int main(void) {
    int array[MAX_ARR_SIZE];
    int *ptrArray[MAX_PTR_ARR_SIZE];
    for (int i = 0; i < MAX_ARR_SIZE; i++) {
        array[i] = 0;
    }
    int n;
    scanf("%d", &n);
    int index[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &index[i]);
        ptrArray[i] = &array[index[i]];
    }
    ptrArray[n] = NULL;
    int numIntersections = countIntersections(ptrArray);
    printf("%d\n", numIntersections);
    return 0;
}
