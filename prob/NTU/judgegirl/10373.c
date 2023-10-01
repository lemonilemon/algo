#include <stdio.h>

#define MAXH 100
#define MAXW 100
#define MAXK 10
void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]) {
    int cnt1 = 0;
    for(int i = 0; i + k - 1 < h; ++i) {
        for(int j = 0; j + k - 1 < w; ++j) {
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
    int imgHeight, imgWidth;
    int colHeight, colWidth;
    int windowSize;
    int imgMat[MAXH][MAXW];
    int colMat[MAXK * MAXK][MAXW * MAXH];
 
    scanf("%d%d", &imgHeight, &imgWidth);
    scanf("%d", &windowSize);
 
    colHeight = windowSize * windowSize;
    colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);
 
    for (int i = 0; i < imgHeight; i++) 
        for (int j = 0; j < imgWidth; j++) 
            scanf("%d", &imgMat[i][j]);
 
    img2col(imgHeight, imgWidth, windowSize, imgMat, colMat);
 
    for (int i = 0; i < colHeight; i++) {
        for (int j = 0; j < colWidth; j++) 
            printf("%d ", colMat[i][j]);
        printf("\n");
    }
}
