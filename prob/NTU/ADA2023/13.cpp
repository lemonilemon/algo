/* 
 * Created : 2023-10-17 02:25:36 lemonilemon
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
const int MAXN = 5005;
const ll INF = 1e18;
ll x[MAXN], y[MAXN];
int indeg[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll dis(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            indeg[i][j] = 0;
            dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < i; ++j) {
            ++indeg[i + 1][j];
            ++indeg[i + 1][i];
        }
    }
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    queue<pair<int, int> > que;
    dp[1][0] = dis(0, 1);
    que.push(make_pair(1, 0));
    while(!que.empty()) {
        auto [u1, u2] = que.front(); // u1 > u2
        que.pop();
        int v = u1 + 1;
        dp[v][u1] = min(dp[v][u1], dp[u1][u2] + dis(u2, v));
        if(!(--indeg[v][u1])) {
            que.push(make_pair(v, u1));
        }
        dp[v][u2] = min(dp[v][u2], dp[u1][u2] + dis(u1, v));
        if(!(--indeg[v][u2])) {
            que.push(make_pair(v, u2));
        }
    }
    ll ans = INF;
    for(int i = 0; i <= n; ++i) {
        ans = min(dp[n][i] + dis(n, 0) + dis(i, 0), ans);
    }
    cout << ans << '\n';
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

