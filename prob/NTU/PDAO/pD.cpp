#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 2e5 + 5;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};
struct Query {
    int a, b, k;
};
int val[MAXN];
int rt[MAXN];
int rk[MAXN];
int findroot(int k) {
    return k == rt[k] ? k : rt[k] = findroot(rt[k]);
}
void merge(int k1, int k2) {
    int r1 = findroot(k1), r2 = findroot(k2);
    if(r1 == r2) return;
    if(rk[r1] < rk[r2]) swap(r1, r2);
    rt[r2] = r1;
    rk[r1] += rk[r2];
    return;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
