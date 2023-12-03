#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int perm[16];
int ansperm[16];
bool color[16];
bool adj[16][16];
int mx;
int n, m;
void permute(int u, int curmx) {
    if(u == n) {
        mx = curmx;
        for(int i = 0; i < n; ++i) {
            ansperm[i] = perm[i];
        }
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(color[i]) continue;
        perm[u] = i;
        int cmx = curmx;
        for(int v = 0; v < u; ++v) {
            if(!adj[u][v]) continue;
            cmx = abs(perm[u] - perm[v]) > cmx? abs(perm[u] - perm[v]) : cmx;
        }
        if(cmx >= mx) continue;
        color[i] = 1;
        permute(u + 1, cmx);
        color[i] = 0;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u][v] = adj[v][u] = 1;
    }
    mx = 1e9 + 7;
    permute(0, 0);
    for(int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", ansperm[i] + 1);
    }
}
