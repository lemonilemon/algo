#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, MAXM = 2e5 + 5;
vector<int> graph[MAXN], rgraph[MAXN];
int h[MAXN], d[MAXN], rd[MAXN], indeg[MAXN], rindeg[MAXN];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        d[i] = rd[i] = 0;
        indeg[i] = rindeg[i] = 0;
        graph[i].clear();
        rgraph[i].clear();
    }
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    if(!m) {
        set<int> s;
        int mn = k, mx = 0;
        for(int i = 1; i <= n; ++i) {
            mn = min(h[i], mn);
            mx = max(h[i], mx);
            s.insert(h[i]);
        }
        int dis = mx - mn;
        for(int i = 1; i <= n; ++i) {
            auto p = s.lower_bound(h[i]);
            if(p != s.begin()) {
                dis = min(dis, k + *prev(p) - h[i]);
            }
        }
        cout << dis << '\n';
        return;
    }
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
        ++indeg[v];
        ++rindeg[u];
    }
    queue<int> que;
    for(int i = 1; i <= n; ++i) {
        if(!indeg[i]) {
            que.push(i);
            d[i] = 0;
        }
    }
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(auto v : graph[u]) {
            d[v] = max(d[v], d[u] + (h[v] < h[u]));
            --indeg[v];
            if(!indeg[v]) que.push(v);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!rindeg[i]) {
            que.push(i);
            rd[i] = 0;
        }
    }
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(auto v : rgraph[u]) {
            rd[v] = max(rd[v], rd[u] + (h[v] > h[u]));
            --rindeg[v];
            if(!rindeg[v]) que.push(v);
        }
    }
    int mxd = 0;
    for(int i = 1; i <= n; ++i) {
        mxd = max(mxd, d[i]);
        // cerr << i << ' ' << d[i] << ' ' << rd[i] << '\n';
    }
    int mnt = k, mxt = 0;
    for(int i = 1; i <= n; ++i) {
        if(rd[i] == mxd) mnt = min(mnt, h[i]); 
        if(d[i] == mxd) mxt = max(mxt, h[i]); 
    }
    cout << 1ll * mxd * k + mxt - mnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
