/* 
 * Created : 2023-09-25 23:08:54 lemonilemon
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
#endif

// constants
const int MAXN = 2e5 + 5;
ll a[MAXN], sz[MAXN];
ll dp[MAXN], ans[MAXN];
vector<int> graph[MAXN];
void dfs(int u = 1, int pa = -1) {
    sz[u] = 1;
    dp[u] = 0;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + 1ll * (a[v] ^ a[u]) * sz[v];
    }
}
void redfs(int u = 1, int pa = -1, ll curans = ans[1]) {
    ans[u] = curans;
    for(auto v : graph[u]) {
        if(v == pa) continue; 
        redfs(v, u, curans + 1ll * (sz[1] - 2 * sz[v]) * (a[v] ^ a[u]));
    }
}


// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        sz[i] = 0;
        dp[i] = 0;     
        ans[i] = 0;
        graph[i].clear();
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs();
    ans[1] = dp[1];
    redfs();
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
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

