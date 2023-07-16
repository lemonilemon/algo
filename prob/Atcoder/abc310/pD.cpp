#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int color[MAXN];
vector<int> dont[MAXN];
int n, t, m;
int dfs(int u = 1, int colorcnt = 0) {
    if(u == n + 1) {
        if(colorcnt == t) return 1;
        return 0;
    }
    set<int> cant; 
    for(auto v : dont[u]) {
        cant.insert(color[v]);
    }
    int cnt = 0;
    for(int i = 1; i <= colorcnt; ++i) {
        if(cant.count(i)) continue; 
        color[u] = i;
        cnt += dfs(u + 1, colorcnt);
    }
    if(colorcnt < t) {
        color[u] = ++colorcnt;
        cnt += dfs(u + 1, colorcnt);
    }
    return cnt;
}
void solve() {
    cin >> n >> t >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if(v > u) swap(u, v);
        dont[u].push_back(v);
    }
    cout << dfs() << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
