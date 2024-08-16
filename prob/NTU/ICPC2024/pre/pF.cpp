/* 
 * Created : 2024-08-16 18:56:12 lemonilemon
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
const int MAXN = 19;
double p[MAXN], d[MAXN], q[MAXN];
double E[MAXN];

bool vis[MAXN][MAXN];
double dis[MAXN][MAXN];
double pos[1 << MAXN];
double dp[MAXN][1 << MAXN];



// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dis[i][j] = 1e18;
            vis[i][j] = 0;
        }
        dis[i][i] = 0;
        vis[i][i] = 1;
        for(int j = 0; j < (1 << n); ++j) {
            dp[i][j] = 1e18;
        }
    }
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for(int i = 0; i < n; ++i) {
        E[i] = q[i] + d[i];
    }
    for(int i = 0; i < (1 << n); ++i) {
        pos[i] = 1;
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1) {
                pos[i] *= 1 - p[j];
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        --u, --v;
        dis[u][v] = dis[v][u] = w;
        vis[u][v] = vis[v][u] = 1;
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                vis[i][j] |= vis[i][k] & vis[k][j]; 
            }
        }
    }
    dp[0][0] = 0;
    for(int k = 0; k < (1 << n); ++k) {
        for(int i = 0; i < n; ++i) { // from i
            for(int j = 0; j < n; ++j) { // to j
                if(!vis[i][j] || dp[i][k] >= 1e18) continue;
                dp[j][k | (1 << j)] = min(dp[j][k | (1 << j)], dp[i][k] + (dis[i][j] + p[j] * d[j]) * pos[k]);
                dp[j][k] = min(dp[j][k], dp[i][k] + dis[i][j] * pos[k]);
            } 
        }
    }
    double ans = 1e18;
    for(int k = 0; k < (1 << n); ++k) {
        for(int i = 0; i < n; ++i) { // from i
            for(int j = 0; j < n; ++j) { // to j
                if(k >> j & 1) ans = min(ans, dp[i][k] + dis[i][j] + E[j] * pos[k]);
            }
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
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

