/* 
 * Created : 2024-08-31 20:38:39 lemonilemon
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
const int MAXN = 405, MAXM = 2e5 + 5;
const ll INF = 1e18 + 7;
ll dis[MAXN][MAXN];
int u[MAXM], v[MAXM];
ll w[MAXM];
int b[5];


// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        dis[u[i]][v[i]] = min(dis[u[i]][v[i]], w[i]);
        dis[v[i]][u[i]] = min(dis[v[i]][u[i]], w[i]);
    }
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        for(int i = 0; i < k; ++i) {
            cin >> b[i];
        }
        ll ans = INF;
        do {
            for(int i = 0; i < 1 << k; ++i) {
                ll d = 0;
                int last = 1;
                for(int j = 0; j < k; ++j) {
                    if((i >> j) & 1) swap(u[b[j]], v[b[j]]);
                }
                for(int j = 0; j < k; ++j) {
                    d += dis[last][u[b[j]]]; 
                    d += w[b[j]];
                    last = v[b[j]];
                }
                d += dis[last][n];
                /*if(d < ans) {
                    debug(d);
                    for(int j = 0; j < k; ++j) {
                        debug(i, j, b[j]);
                    }
                }*/
                ans = min(ans, d);
                for(int j = 0; j < k; ++j) {
                    if((i >> j) & 1) swap(u[b[j]], v[b[j]]);
                }
            }
        } while(next_permutation(b, b + k));
        cout << ans << '\n';
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

