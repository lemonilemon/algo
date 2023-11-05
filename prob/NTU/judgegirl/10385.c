#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAXN = 55;
char mat[55][55] = {{ 0 }};
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
int rx, ry;
int dfs(int x, int y, int fx, int fy, bool print) {
    print && printf("%c", mat[x][y]);
    int cnt = (bool)(isalpha(mat[x + dx[0]][y + dy[0]])) +
              (bool)(isalpha(mat[x + dx[1]][y + dy[1]])) +
              (bool)(isalpha(mat[x + dx[2]][y + dy[2]])) +
              (bool)(isalpha(mat[x + dx[3]][y + dy[3]]));
    //printf("%d %d %d\n", x, y, cnt);
    if(cnt == 1 && (fx != -1 && fy != -1)) {
        //printf("%d %d %d %d\n", x, y, rx, ry);
        if(mat[x][y] != mat[rx][ry]) {
            (mat[x][y] < mat[rx][ry]) && ((rx = x) && (ry = y));
        } else if(x != rx) {
            (x < rx) && ((rx = x) && (ry = y));
        } else {
            (y < ry) && ((rx = x) && (ry = y));
        }
        return 0;
    }
    (isalpha(mat[x + dx[0]][y + dy[0]]) && (x + dx[0] != fx || y + dy[0] != fy)) && dfs(x + dx[0], y + dy[0], x, y, print);
    (isalpha(mat[x + dx[1]][y + dy[1]]) && (x + dx[1] != fx || y + dy[1] != fy)) && dfs(x + dx[1], y + dy[1], x, y, print);
    (isalpha(mat[x + dx[2]][y + dy[2]]) && (x + dx[2] != fx || y + dy[2] != fy)) && dfs(x + dx[2], y + dy[2], x, y, print);
    (isalpha(mat[x + dx[3]][y + dy[3]]) && (x + dx[3] != fx || y + dy[3] != fy)) && dfs(x + dx[3], y + dy[3], x, y, print);
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; ++i) {
        mat[0][i] = mat[n + 1][i] = '0';
        mat[i][0] = '0';
        fgets(mat[i] + 1, n + 1, stdin);
        getchar();
        mat[i][n + 1] = '0';
    }
    mat[0][n + 1] = '0';
    for(int i = 1; i <= n; ++i) {
        bool flag = 1;
        for(int j = 1; j <= n; ++j) {
            if(!isalpha(mat[i][j])) continue;
            int cnt = (bool)(isalpha(mat[i + dx[0]][j + dy[0]])) +
                      (bool)(isalpha(mat[i + dx[1]][j + dy[1]])) +
                      (bool)(isalpha(mat[i + dx[2]][j + dy[2]])) +
                      (bool)(isalpha(mat[i + dx[3]][j + dy[3]]));
            rx = i, ry = j;
            if(cnt == 1) {
                dfs(rx, ry, -1, -1, 0);
                flag = 0;
                break;
            }
        }
        if(!flag) break;
    }
    dfs(rx, ry, -1, -1, 1);
}
