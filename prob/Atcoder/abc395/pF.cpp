/*
 * Created : 2025-03-01 20:33:00 lemonilemon
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
const ll INF = 1e18;
vector<pair<int, ll>> graph[MAXN];
ll dis[MAXN];
int U[MAXN], D[MAXN];
// solution
void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> U[i] >> D[i];
    }
    dis[0] = 0;
    for (int i = 1; i <= n + 1; ++i) {
        dis[i] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        graph[0].push_back({i, U[i]});
        graph[i].push_back({n + 1, D[i]});
        if (i == n)
            continue;
        graph[i + 1].push_back({i, x});
        graph[i].push_back({i + 1, x});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v, w] : graph[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    ll H = dis[n + 1];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += U[i] + D[i] - H;
    }
    cout << ans << '\n';
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
