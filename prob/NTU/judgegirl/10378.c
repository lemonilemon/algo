#include <stdio.h>
#include <assert.h>
// #include "rotate.h"
#define MAX 500
 
void rotate(int *P[MAX][MAX], int n) {
    int *temp[MAX][MAX];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            temp[j][n - i - 1] = P[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            P[i][j] = temp[i][j];
        }
    }
    
}

int main() {
    int array[MAX][MAX], check[MAX][MAX];
    int *P[MAX][MAX];
 
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            P[i][j] = &array[i][j];
            scanf("%d", &array[i][j]);
            check[i][j] = array[i][j];
        }
    }
 
    rotate(P, n);
 
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            assert(check[i][j] == array[i][j]);
            printf("%d ", *(P[i][j]));
        }
        printf("\n");
    }
 
    return 0;
}
