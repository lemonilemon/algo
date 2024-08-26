/* 
 * Created : 2024-08-26 18:00:37 lemonilemon
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
const ll INF = 1e18 + 9;
ll dis[MAXN];
vector<pair<int, ll> > graph[MAXN];

// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    for(int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    dis[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
    pq.push({dis[1], 1}); 
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : graph[u]) {
            if(d + w < dis[v]) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << dis[i] << " \n"[i == n];
    }
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

