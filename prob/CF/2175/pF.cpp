/*
 * Created : 2026-02-10 23:19:16 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;

#define LOCAL

// debug template
#ifdef LOCAL
#define debug(args...) _debug(#args, args)
#define expand(arr, l, r) _expand(#arr, l, r, begin(arr) + l, begin(arr) + r)
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
struct DSU {
    DSU(int n) {
        rt.resize(n + 1);
        rk.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            rt[i] = i;
        }
    }
    vector<int> rt, rk;
    int findroot(int x) { return rt[x] == x ? x : rt[x] = findroot(rt[x]); }
    bool setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if (r1 == r2) {
            return false;
        }
        if (rk[r1] < rk[r2]) {
            swap(r1, r2);
        }
        rt[r2] = r1;
        rk[r1] += rk[r2];
        return true;
    }
    void reset() {
        for (int i = 0; i < rt.size(); ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
};
int st[MAXN], ed[MAXN];
int timer;
void dfs(int u, int par = -1) {
    if (par == -1)
        timer = 0;
    st[u] = ++timer;
    for (auto v : graph[u]) {
        if (v == par)
            continue;
        dfs(v, u);
    }
    ed[u] = timer;
}
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
    }
    vector<tuple<int, int, int>> edges(m);
    for (auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    ll sum = 0;
    DSU dsu(n);
    bool flag = true;
    vector<tuple<int, int, int>> tree_edges;
    for (int i = 0; i < n - 1; ++i) {
        auto [w, u, v] = edges[i];
        if (!dsu.setunion(u, v)) {
            flag = false;
        } else {
            tree_edges.push_back({w, u, v});
        }
        sum += w;
    }
    if (flag) {
        cout << sum << '\n';
        return;
    }
    for (auto [w, u, v] : tree_edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
