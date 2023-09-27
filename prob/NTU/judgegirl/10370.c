#include <stdio.h>
#include <stdbool.h>
const int MAXN = 105;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
    int n;
    scanf("%d", &n);
    int mat[MAXN][MAXN]; 
    int corner[MAXN][MAXN];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            mat[i][j] = 0;
            corner[i][j] = 0;
            scanf("%d", &mat[i][j]);
        }
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        corner[x][y] = 1;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) { 
            if(!corner[i][j]) continue;
            int cnt[4] = {0};
            for(int ori = 0; ori < 4; ++ori) {
                int x = i + dx[ori], y = j + dy[ori];
                while(x >= 0 && x < n && y >= 0 && y < n) {
                    if(mat[x][y]) {
                        ++cnt[ori];
                        mat[x][y] = 0;
                    } else break;
                    x += dx[ori], y += dy[ori];
                }
            }
            mat[i][j] = 0;
            if(cnt[0]) {
                if(cnt[1]) printf("3 %d %d\n", cnt[0] + 1, cnt[1] + 1);
                else printf("2 %d %d\n", cnt[0] + 1, cnt[3] + 1); 
            } else {
                if(cnt[1]) printf("0 %d %d\n", cnt[2] + 1, cnt[1] + 1);
                else printf("1 %d %d\n", cnt[2] + 1, cnt[3] + 1);
            }
        }
    }
}
