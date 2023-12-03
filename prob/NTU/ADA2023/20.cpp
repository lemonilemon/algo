/* 
 * Created : 2023-11-21 04:46:22 lemonilemon
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
const int MAXN = 3e5 + 5;
const ll INF = MAXN - 1;
vector<int> graph[MAXN];
ll dis[MAXN];
vector<int> rgraph[MAXN];
ll rdis[MAXN];
ll layer[MAXN];
ll rlayer[MAXN];
// solution
void solve() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        layer[i] = rlayer[i] = 0;
        dis[i] = rdis[i] = INF;
    }
    dis[s] = 0;
    rdis[t] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();        
        que.pop();
        ++layer[dis[u]];
        for(auto v : graph[u]) {
            if(dis[v] == INF) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    que.push(t);
    while(!que.empty()) {
        int u = que.front();        
        que.pop();
        ++rlayer[rdis[u]];
        for(auto v : rgraph[u]) {
            if(rdis[v] == INF) {
                rdis[v] = rdis[u] + 1;
                que.push(v);
            }
        }
    }
    ll mn = INF;
    for(int i = 1; i <= n; ++i) {
        mn = min(mn, dis[i] + rdis[i]);
    }
    ll cnt = n * n - m;
    ll cur = 0;
    for(ll d1 = mn; d1 >= 0; --d1) {
        ll d2 = mn - d1 - 2;
        if(d2 >= 0) cur += rlayer[d2];
        cnt -= 1ll * layer[d1] * cur;
    }
    cout << cnt << '\n';
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

