#include <stdio.h>
long long int dis2(int x1, int y1, int x2, int y2) {
    return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
}
int main() {
    const int MAXN = 50005;
    const long long int INF = 1e18 + 9;
    int n;
    scanf("%d", &n);
    int x[MAXN], y[MAXN];
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    int tx, ty;
    scanf("%d %d", &tx, &ty);
    int mnidx[MAXN], mncnt = 0;
    long long int mn = INF;
    for(int i = 0; i < n; ++i) {
        long long int d2 = dis2(x[i], y[i], tx, ty);
        if(d2 < mn) {
            mn = d2;
            mncnt = 0;
            mnidx[mncnt++] = i;
        } else if(d2 == mn) mnidx[mncnt++] = i;
    }
    for(int i = 0; i < mncnt; ++i) {
        printf("%d\n", mnidx[i]);
    }
}
