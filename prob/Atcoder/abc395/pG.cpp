/*
 * Created : 2025-03-01 21:11:01 lemonilemon
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
typedef vector<vector<ll>> Mat;
const ll INF = 1e18;
const int MAXN = 85;
Mat dis[MAXN];
Mat mul(Mat a, Mat b) {
    Mat ret(a.size(), vector<ll>(b[0].size(), INF));
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b[0].size(); ++j)
            for (int k = 0; k < b.size(); ++k)
                ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
    return ret;
}
Mat finaldis;
struct Edge {
    ll w;
    int u, v;
};
struct DSU {
    int rt[MAXN];
    int rk[MAXN];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
    int find(int x) { return rt[x] == x ? x : rt[x] = find(rt[x]); }
    bool setunion(int k1, int k2) {
        int p1 = find(k1);
        int p2 = find(k2);
        if (p1 == p2)
            return 0;
        if (rk[p1] < rk[p2])
            swap(p1, p2);
        rt[p2] = p1;
        rk[p1] += rk[p2];
        return 1;
    }
} dsu;
// solution
void solve() {
    int n, k;
    cin >> n >> k;
    dis[0].resize(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dis[0][i][j];
        }
    }
    for (int t = 1; t <= n; ++t) {
        dis[t] = mul(dis[t - 1], dis[t - 1]);
    }
    finaldis.resize(n, vector<ll>(n, INF));
    for (int t = 0; t <= n; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                finaldis[i][j] = min(finaldis[i][j], dis[t][i][j]);
            }
        }
    }
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({finaldis[i][j], i + 1, j + 1});
        }
    }
    sort(edges.begin(), edges.end(), [&](Edge a, Edge b) { return a.w < b.w; });
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << finaldis[i][j] << " \n"[j == n - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        dsu.init(k);
        int s, t;
        cin >> s >> t;
        dsu.rt[s] = s;
        dsu.rk[s] = 1;
        dsu.rt[t] = t;
        dsu.rk[t] = 1;
        ll ans = 0;
        for (auto [w, u, v] : edges) {
            if (u > k && u != s && u != t)
                continue;
            if (v > k && v != s && v != t)
                continue;
            if (dsu.setunion(u, v)) {
                // debug(u, v, w);
                ans += w;
            }
        }
        cout << ans << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
