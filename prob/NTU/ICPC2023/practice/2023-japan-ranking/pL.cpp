/* 
 * Created : 2023-09-12 20:03:29 lemonilemon
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
const int MOD = 998244353;
vector<int> cen, d2v[MAXN], graph[MAXN]; 
map<int, int> subtree_tags[MAXN];
int tag[MAXN], sz[MAXN], p[MAXN], dp[MAXN];
int n;
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
void dfs_sz(int u = 1, int pa = -1) {
    sz[u] = 1;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
    return;
}
void dfs_cen(int u = 1, int pa = -1) {
    int mxsub = n - sz[u];
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs_cen(v, u);
        mxsub = max(mxsub, sz[v]);
    }
    if((mxsub << 1) <= n) cen.push_back(u);
    return;
}
int dfs_height(int u, int pa = -1, int depth = 0) {
    p[u] = pa;
    int h = 0;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        h = max(h, dfs_height(v, u, depth + 1));
    }
    d2v[depth].push_back(u);
    return ++h;
}
int rooted_iso(int r) {
    for(int i = 0; i <= n; ++i) {
        d2v[i].clear();
        subtree_tags[i].clear();
        tag[i] = 0;
        dp[i] = 1;
    }
    int h = dfs_height(r);
    for(int d = h - 1; d >= 0; --d) {
        sort(d2v[d].begin(), d2v[d].end(), [](int a, int b) {
            return subtree_tags[a] < subtree_tags[b];
        });
        for(int i = 0, cnt = 0; i < (int)d2v[d].size(); ++i) {
            if(i && subtree_tags[d2v[d][i]] != subtree_tags[d2v[d][i - 1]]) ++cnt;
            tag[d2v[d][i]] = cnt;
            // debug(d, d2v[d][i], tag[d2v[d][i]]);
        }
        for(auto u : d2v[d]) {
            if(~p[u]) {
                if(subtree_tags[p[u]].count(tag[u])) ++subtree_tags[p[u]][tag[u]];
                else subtree_tags[p[u]][tag[u]] = 1;
                dp[p[u]] = mmul(dp[p[u]], mmul(dp[u], subtree_tags[p[u]][tag[u]]));
            }
        }
    }
    return dp[r];
}
// solution
void solve() {
    // init    
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        debug(i, rooted_iso(i));
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

