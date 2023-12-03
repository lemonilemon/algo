#include <stdio.h>
#include <stdbool.h>
int u[36], v[36];
bool color[36];
bool get[64];
int mx;
void dfs(int u, int curcnt) {
    if(u == 36) {
        mx = curcnt;
        return;
    }
    for(int i = 0; i < n; ++i) {
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
    }
}
