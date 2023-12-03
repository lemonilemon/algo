#include <stdio.h>
#include <stdbool.h>
bool adj[1005][1005];
int chosen[55][105]; // (path, sets)
int anschosen[55][105];
int mx;
bool color[1005];
int k, n, sz;
bool flag;
void dfs1(int layer, int cur, int layerpath, int pathcnt) {
    if(pathcnt < mx) return;
    if(layer == k) {
        mx = pathcnt; 
        for(int i = 0; i < pathcnt; ++i) {
            for(int j = 0; j < k; ++j) {
                anschosen[i][j] = chosen[i][j];
            }
        }
        return;
    }
    if(cur == pathcnt) {
        dfs(layer + 1, 0, pathcnt, pathcnt);
        return;
    }
    int u = chosen[cur][layer - 1];
    for(int v = (u / sz + 1) * sz; v < (u / sz + 2) * sz; ++v) {
        
    }
}
void dfs2(int 
int main() {
    scanf("%d%d", &k, &n);
    sz = n / k;
    int e;
    scanf("%d", &e);
    for(int i = 0; i < e; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }
    dfs(-1, -1);
}
