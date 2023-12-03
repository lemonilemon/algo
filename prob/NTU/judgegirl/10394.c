#include <stdio.h>
#include <stdbool.h>
bool adj[1005][1005];
int chosen[55][105]; // (path, sets)
int anschosen[55][105];
int mx;
bool color[1005];
int k, n, sz;
bool flag;
void dfs(int layer, int cur, int pathcnt) {
    if(layer == k) {
        flag = 1;
    }
    if(cur == pathcnt)
    for(int i = 0; i < pathcnt; ++i) {
        int u = chosen[i][layer - 1];
        for(int v = (layer + 1) * sz; v < (layer + 2) * sz; ++v) {
            if(!color[v] && adj[u][v]) {
                color[v] = 1;
                chosen[i][layer + 1] = v;
            }
        }
    }
    int pcnt = 0;
    dfs(layer + 1);
}
void dfs1(int path, int u) {
    if(u / sz == k - 1) {
        return;
    }
}
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
