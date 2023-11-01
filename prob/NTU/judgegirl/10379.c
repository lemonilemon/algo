#include <stdio.h>
#include <assert.h>
// #include "permute.h"

#include <stddef.h>
#define MAX 1000
 
void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
    int* cpyptr[MAX];
    for(int i = 0; i < MAX && ptrPerms[i] != NULL; ++i) {
        for(int j = 0; j < MAX && ptrArray[j] != NULL; ++j) {
            cpyptr[j] = ptrArray[j];
        }
        for(int j = 0; j < MAX && ptrArray[j] != NULL; ++j) {
            ptrArray[j] = cpyptr[ptrPerms[i][j]];
        }
    }
}
 
int main() {
    int n, array[MAX], check[MAX];
    int *ptrArray[MAX];
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        ptrArray[i] = &array[i];
        scanf("%d", &array[i]);
        check[i] = array[i];
    }
    ptrArray[n] = NULL;
 
    int m, perms[MAX][MAX];
    int *ptrPerms[MAX];
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++)
            scanf("%d", &perms[i][j]);
        ptrPerms[i] = perms[i];
    }
    ptrPerms[m] = NULL; 
 
    permute(ptrArray, ptrPerms);
 
    for (int i = 0; i<n; i++) {
        assert(array[i] == check[i]);
        printf("%d ", *(ptrArray[i]));
    }
 
    return 0;
}
