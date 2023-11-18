/* 
 * Created : 2023-11-11 12:45:46 lemonilemon
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
const int MAXN = 2e5 + 5;
bool color[MAXN];
ll dp[MAXN];
ll temp[MAXN];
struct DSU {
    int rt[MAXN];
    vector<int> node[MAXN];
    void init() {
        for(int i = 0; i < MAXN; ++i) {
            rt[i] = i;
            node[i].push_back(i);
        }
    }
    int findroot(int k) {
        return rt[k] == k? k : rt[k] = findroot(rt[k]);
    }
    bool merge(int u, int v, ll w) {
        debug(u, v, w);
        int k1 = findroot(u), k2 = findroot(v);
        if(k1 == k2) {
            if(dp[v] == dp[u] + w) return 1;
            return 0;
        }
        if(node[k1].size() <= node[k2].size()) {
            rt[k1] = k2; 
            ll dis = dp[u] - (dp[v] - w);
            for(auto c : node[k1]) {
                node[k2].push_back(c);
                dp[c] -= dis;
                debug(c, dp[c]);
            }
            node[k1].clear();
        } else {
            rt[k2] = k1;
            ll dis = dp[v] - (dp[u] + w);
            for(auto c : node[k2]) {
                node[k1].push_back(c);
                dp[c] -= dis;
                debug(c, dp[c]);
            }
            node[k2].clear();
        }
        return 1;
    }
} dsu;
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    dsu.init();
    vector<int> ans;
    for(int i = 1; i <= q; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        if(dsu.merge(u, v, w)) {
            /*for(int j = 1; j <= n; ++j) {
                cerr << "dp: " << dp[j] << " \n"[j == n];
            }*/
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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

