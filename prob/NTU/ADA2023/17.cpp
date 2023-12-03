/* 
 * Created : 2023-11-21 02:34:21 lemonilemon
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
const int MAXN = 3e5 + 5, MAXM = 3e5 + 5;
const ll INF = 1e18;
vector<pair<int, ll> > graph[MAXN];
ll dis[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    for(int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    for(auto [st, d0] : graph[1]) {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
        for(auto& [v, w] : graph[st]) {
            if(v == 1) w = INF;
        }
        if(d0 < dis[st]) {
            dis[st] = d0;
            pq.push(make_pair(dis[st], st));
        }
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d <= dis[u]) {
                debug(u, d);
                for(auto [v, w] : graph[u]) {
                    if(d + w < dis[v]) {
                        dis[v] = d + w;
                        if(v != 1) pq.push(make_pair(dis[v], v));
                    }
                }
            }
        }       
    }
    cout << dis[1] << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

