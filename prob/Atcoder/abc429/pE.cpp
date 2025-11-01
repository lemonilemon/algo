/*
 * Created : 2025-10-25 20:29:33 lemonilemon
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
const int MAXN = 2e5 + 5;
const int INF = 1e9;
vector<int> graph[MAXN];
int color[MAXN]; // 1: first visited, 2: second visited
int dist[MAXN][2];
int from[MAXN][2];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    string s;
    cin >> s;
    queue<pair<int, int>> que;
    for (int i = 1; i <= n; ++i) {
        dist[i][0] = dist[i][1] = INF;
        from[i][0] = from[i][1] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'S') {
            dist[i][0] = 0;
            from[i][0] = i;
            que.push({i, 0});
            color[i] = 1;
        }
    }
    while (!que.empty()) {
        auto [u, b] = que.front();
        debug(u, b, dist[u][b], from[u][b]);
        que.pop();
        for (auto &v : graph[u]) {
            if (color[v] == 0) {
                debug(u, v, b);
                dist[v][0] = dist[u][b] + 1;
                from[v][0] = from[u][b];
                color[v] = 1;
                debug(v, 0);
                que.push({v, 0});
            } else if (color[v] == 1 && from[v][0] != from[u][b]) {
                debug(u, v, b);
                dist[v][1] = dist[u][b] + 1;
                from[v][1] = from[u][b];
                color[v] = 2;
                debug(v, 1);
                que.push({v, 1});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'D') {
            cout << dist[i][0] + dist[i][1] << '\n';
        }
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
