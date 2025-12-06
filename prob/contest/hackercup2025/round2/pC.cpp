/*
 * Created : 2025-11-16 02:41:54 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;

// #define LOCAL

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
vector<vector<pair<int, int>>> graph;
struct Segtree {
    vector<int> _route;
    vector<int> tree;

    Segtree(vector<int> route) {
        _route = route;
        tree.resize(route.size() * 4);
        build(1, 0, route.size() - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = _route[tl];
            return;
        }
        int current_node = graph.size();
        graph.push_back({});
        int mid = (tl + tr) / 2;
        build(v << 1, tl, mid);
        graph[current_node].push_back({tree[v << 1], 0});
        build(v << 1 | 1, mid + 1, tr);
        graph[current_node].push_back({tree[v << 1 | 1], 0});
        tree[v] = current_node;
    }

    void connect(int u, int w, int ql, int qr, int v, int tl, int tr) {
        if (ql == tl && qr == tr) {
            debug(u, ql, qr, tree[v]);
            graph[u].push_back({tree[v], w});
            return;
        }
        int mid = (tl + tr) / 2;
        if (qr <= mid) {
            connect(u, w, ql, qr, v << 1, tl, mid);
        } else if (ql > mid) {
            connect(u, w, ql, qr, v << 1 | 1, mid + 1, tr);
        } else {
            connect(u, w, ql, mid, v << 1, tl, mid);
            connect(u, w, mid + 1, qr, v << 1 | 1, mid + 1, tr);
        }
    }

    void ride(int u, int k) {
        if (u >= ((int)_route.size() - 1))
            return;
        connect(_route[u], 1, u + 1, min((int)_route.size() - 1, u + k), 1, 0,
                (int)_route.size() - 1);
    }
};

vector<Segtree> campus_routes;

// solution
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    campus_routes.clear();
    graph.clear();
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        vector<int> route(l);
        for (int j = 0; j < l; ++j) {
            cin >> route[j];
        }
        campus_routes.push_back(Segtree(route));
        for (int j = 0; j < l; ++j) {
            campus_routes.back().ride(j, k);
        }
    }
    vector<int> dist(graph.size(), INT_MAX);
    deque<int> dq;
    dist[1] = 0;
    dq.push_back(1);
    while (!dq.empty()) {
        auto u = dq.front();
        dq.pop_front();
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        debug(i, dist[i]);
        if (dist[i] == INT_MAX)
            dist[i] = -1;
        ans += 1ll * dist[i] * i;
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
