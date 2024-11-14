/*
 * Created : 2024-11-09 23:05:12 lemonilemon
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
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 1e5 + 5;
set<int> graph[MAXN];
void flip(int a, int b) {
    if(graph[a].count(b)) {
        graph[a].erase(b);
        graph[b].erase(a);
    } else {
        graph[a].insert(b);
        graph[b].insert(a);
    }
}
vector<tuple<int, int, int> > ans;
void choose(int a, int b, int c) {
    flip(a, b);
    flip(b, c);
    flip(a, c);
    ans.push_back({a, b, c});
}
bool vis[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    ans.clear();
    for(int i = 1; i <= n; ++i) {
        vis[i] = 0;
        graph[i].clear();
    }
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    bool flag = 1;
    int st = 0;
    int connect = 0;
    for(int u = 1; u <= n; ++u) {
        vector<int> edges;
        for(auto v : graph[u]) {
            edges.push_back(v);
        }
        for(int i = 1; i < edges.size(); i += 2) {
            int v1 = edges[i - 1], v2 = edges[i];
            choose(u, v1, v2);
        }

    }
    for(int u = 1; u <= n; ++u) {
        if(graph[u].size() > 0) {
            flag = 0;
            st = u;
            connect = *graph[u].begin();
        }
    }
    if(!flag) {
        vis[st] = 1;
        vis[connect] = 1;
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            if(graph[i].size() > 0) {
                vis[*graph[i].begin()] = 1;
            }
            vis[i] = 1;
            choose(st, i, connect);
            connect = i;
        }

    }
    cout << ans.size() << '\n';
    for(auto [a, b, c] : ans) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return;

}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
