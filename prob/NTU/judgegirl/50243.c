#include <stdio.h>
#include <stdbool.h>
int n, m;
bool color[66];
int ans[66], anscnt = 65;
bool adj[66][66];
void dfs(int u, int c) {
    if(c > anscnt) return;
    if(u >= n) {
        int cnt = 0;
        int cur[65];
        for(int i = 0; i < n; ++i) {
            if(color[i]) cur[cnt++] = i;
        }
        // printf("cnt:%d\n", cnt);
        if(cnt < anscnt) {
            for(int i = 0; i < anscnt; ++i) {
                ans[i] = 0;
            }
            anscnt = cnt;
            for(int i = 0; i < cnt; ++i) {
                ans[i] = cur[i];
            }
        } else if(cnt == anscnt) {
            for(int i = 0; i < cnt; ++i) {
                if(cur[i] < ans[i]) break;
                if(cur[i] > ans[i]) return; 
            }
            for(int i = 0; i < cnt; ++i) {
                ans[i] = cur[i];
            }
        }
        return;  
    }
    color[u] = 0;
    bool flag = 1;
    for(int v = 0; v < u; ++v) {
        if(u == v) continue;
        if(adj[u][v] && color[v] == 0) {
            flag = 0; 
            break;
        }
    }
    if(flag) dfs(u + 1, c);
    color[u] = 1;
    dfs(u + 1, c + 1);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    dfs(0, 0);
    for(int i = 0; i < anscnt; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
