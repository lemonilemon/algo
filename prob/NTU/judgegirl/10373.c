#include <stdio.h>
#define MAXR 100
#define MAXC 100
#define MAXK 10

void img2col(int r, int c, int k, int imgMatrix[MAXR][MAXC], int colMatrix[MAXR * MAXC][MAXK * MAXK]) {
    int cnt1 = 0;
    for(int i = 0; i + k - 1 < r; ++i) {
        for(int j = 0; j + k - 1 < c; ++j) {
            int cnt2 = 0;
            for(int l = i; l < i + k; ++l) {
                for(int m = j; m < j + k; ++m) {
                    colMatrix[cnt2][cnt1] = imgMatrix[l][m];
                    ++cnt2;
                }
            }
            ++cnt1;
        } 
    }
}

int main() {
    int imgRows, imgCols;
    int colRows, colCols;
    int windowSize;
    int imgMat[MAXR][MAXC];
    int colMat[MAXR * MAXC][MAXK * MAXK];
 
    scanf("%d%d", &imgRows, &imgCols);
    scanf("%d", &windowSize);
 
    colRows = (imgRows - windowSize + 1) * (imgCols - windowSize + 1);
    colCols = windowSize * windowSize;
 
    for (int i = 0; i < imgCols; i++)
        for (int j = 0; j < imgRows; j++)
            scanf("%d", &imgMat[j][i]);
 
    img2col(imgRows, imgCols, windowSize, imgMat, colMat);
 
    for (int i = 0; i < colCols; i++) {
        for (int j = 0; j < colRows; j++)
            printf("%d ", colMat[j][i]);
        printf("\n");
    }
}
