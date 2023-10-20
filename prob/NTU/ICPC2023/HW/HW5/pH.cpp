/* 
 * Created : 2023-10-13 03:44:20 lemonilemon
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
// constants
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
vector<int> d2v[MAXN << 1], subtree_tags[MAXN << 1], graph[MAXN << 1];
int p[MAXN << 1], d[MAXN << 1], d1[MAXN << 1], d2[MAXN << 1], tag[MAXN << 1], sz[MAXN << 1], dp[MAXN << 1];
int n;
void dfs(int u, int pa = -1, int dis = 0) {
    d[u] = dis;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs(v, u, dis + 1);
    }
}
void dfs1(int u, int pa = -1, int dis = 0) {
    d1[u] = dis;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs1(v, u, dis + 1);
    }
}
void dfs2(int u, int pa = -1, int dis = 0) {
    d2[u] = dis;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs2(v, u, dis + 1);
    }
}
int dfs_height(int u, int pa = -1, int depth = 0) {
    d[u] = depth;
    p[u] = pa;
    int h = 0;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        h = max(h, dfs_height(v, u, depth + 1));
    }
    ++h;
    d2v[depth].push_back(u);
    return h;
}
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
void rooted_iso(int r) {
    for(int i = 0; i <= n; ++i) {
        d2v[i].clear();
    }
    for(int i = 0; i <= n; ++i) {
        subtree_tags[i].clear();
        p[i] = -1;
        tag[i] = 0;
    }
    int h = dfs_height(r);
    for(int i = h - 1; i >= 0; --i) {
        sort(d2v[i].begin(), d2v[i].end(), [](int a, int b) {
            return subtree_tags[a] < subtree_tags[b];
        });
        for(int j = 0, cnt = 0; j < (int)d2v[i].size(); ++j) {
            if(j && subtree_tags[d2v[i][j]] != subtree_tags[d2v[i][j - 1]]) ++cnt;
            tag[d2v[i][j]] = cnt;
        }
        for(auto u : d2v[i]) {
            map<int, int> mp;
            dp[u] = 1;
            for(auto v: graph[u]) {
                if(v == p[u]) continue;
                dp[u] = mmul(dp[v], dp[u]);
                if(!mp.count(tag[v])) mp[tag[v]] = 1;
                else dp[u] = mmul(dp[u], ++mp[tag[v]]);
            }
            if(~p[u]) subtree_tags[p[u]].push_back(tag[u]);
        }
    }
}
// solution
void solve() {
    cin >> n;
    int cur = n + 1;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(cur);
        graph[cur].push_back(u);
        graph[cur].push_back(v);
        graph[v].push_back(cur);
        ++cur;
    }
    n = n * 2 - 1;
    dfs(1);
    int p1 = 1;
    for(int i = 1; i <= n; ++i) {
        if(d[i] > d[p1]) p1 = i;
    }
    dfs(p1);
    int p2 = 1;
    for(int i = 1; i <= n; ++i) {
        if(d[i] > d[p2]) p2 = i;
    }
    dfs1(p1);
    dfs2(p2);
    int r = 1;
    for(int i = 2; i <= n; ++i) {
        if(max(d1[i], d2[i]) < max(d1[r], d2[r])) r = i;
    }
    debug(p1, p2, r);
    rooted_iso(r);
    cout << dp[r] << '\n';
    return;
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

