#include <stdio.h>
#include <stdbool.h>
int n, m;
int u[36], v[36];
bool color[36];
int ans[36];
int rm[36][36];
int cant[36];
int mx;
void dfs(int cur, int curcnt) {
    if(m - cur + curcnt <= mx) return;
    if(cur == m) {
        mx = curcnt;
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            color[i] && (ans[cnt++] = i);
        }
        return;
    }
    if(!cant[cur]) {
        color[cur] = 1;
        for(int i = 0; i < cur; ++i) {
            (color[i] && rm[i][cur] != -1) && ++cant[rm[i][cur]];
        }
        dfs(cur + 1, curcnt + 1);
        for(int i = 0; i < cur; ++i) {
            (color[i] && rm[i][cur] != -1) && --cant[rm[i][cur]];
        }
        color[cur] = 0;
    }
    dfs(cur + 1, curcnt);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        for(int j = 0; j < m; ++j) {
            rm[i][j] = -1;
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = i + 1; j < m; ++j) {
            for(int k = 0; k < m; ++k) {
                if(u[i] == u[j] && ((v[i] == u[k] && v[j] == v[k]) || (v[i] == v[k] && v[j] == u[k]))) {
                    rm[i][j] = k; 
                    rm[j][i] = k;
                    rm[i][k] = j;
                    rm[k][i] = j;
                    rm[j][k] = i;
                    rm[k][j] = i;
                }
            }
        }
    }

    dfs(0, 0);
    for(int i = 0; i < mx; ++i) {
        printf("%d %d\n", u[ans[i]], v[ans[i]]);
    }
}
