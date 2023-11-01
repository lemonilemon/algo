#include <stdio.h>
#include <stdlib.h>
// #include "calRectArea.h"
#define MAXM 200
int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]) {
    int ans = 0;
    for(int i = 0; i < M; ++i) {
        int dis = ptrRight[i] - ptrLeft[i];
        int w = dis % N + 1, h = dis / N + 1;
        ans += w * h;
    }
    for(int i = 1; i < M; ++i) {
        int dis = ptrRight[i - 1] - ptrLeft[i];
        int w = dis % N + 1, h = dis / N + 1;
        ans -= w * h;
    }
    return ans;
}
 
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
 
    int *ptrMatrix;
    int matrix[N][N];
    int *ptrLeft[MAXM];
    int *ptrRight[MAXM];
    int x, y, w, h;
 
    ptrMatrix = &matrix[0][0];
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        ptrLeft[i] = &matrix[x][y];
        ptrRight[i] = &matrix[x + w - 1][y + h - 1];
    }
    int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
    printf("%d\n", area);
}
