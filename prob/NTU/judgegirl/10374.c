#include <stdio.h>
int main() {
    const int MAXN = 205, MAXM = 205;
    int mat[MAXN][MAXM];
    int n, m, l, w;
    scanf("%d%d%d%d", &n, &m, &l, &w);
    int x, y;
    scanf("%d%d", &x, &y);
    int s, k;
    scanf("%d%d", &s, &k);
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &mat[j][i]);
        }
    }
    if(x >= m || y >= n) {
        int mx = y - n + 1;
        if(x - m + 1 > mx) mx = x - m + 1;
        int cnt = (mx + s - 1) / s;
        k -= cnt;
        x -= cnt * s;
        y -= cnt * s;
    }
    do {
        for(int i = n - 1; i >= 0; --i) { // y
            for(int j = 0; j < m; ++j) { // x
                if(j) printf(" ");
                if(j >= x && j < x + w && i >= y && i < y + l) printf("0");
                else printf("%d", mat[j][i]);
            }
            printf("\n");
        } 
        printf("\n");
        x -= s, y -= s, --k;
    } while(k >= 0 && x + w > 0 && y + l > 0);
    return 0; 
}
