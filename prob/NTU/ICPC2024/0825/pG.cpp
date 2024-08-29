/* 
 * Created : 2024-08-29 16:37:44 lemonilemon
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
const int MAXN = 1e5 + 5, MAXM = 1e5 + 5, MAXC = 20;
const int MOD = 1e9 + 7, INV2 = (MOD >> 1) + 1;

ll p[MAXC];
int color[MAXN];
ll times[1 << MAXC];
ll points[1 << MAXC];
ll sum[1 << MAXC];

void fwt(ll *a, int n, ll op) { //xor
    for(int L = 2; L <= n; L <<= 1) {
        for(int i = 0; i < n; i += L) {
            for(int j = i; j < i + (L >> 1); ++j) {
                ll tx = a[j], ty = a[j + (L >> 1)];
                a[j] = (tx + ty) * op % MOD;
                a[j + (L >> 1)] = (tx - ty + MOD) * op % MOD;
            }
        }
    }
}



vector<int> graph[MAXN];

int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];

void dfs1(int u, int pa = -1) {
    son[u] = -1;
    sz[u] = 1;
    fa[u] = pa;
    if(~pa) dep[u] = dep[pa] + 1;
    else dep[u] = 0;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        if(!dep[v]) {
            dfs1(v, u);
            sz[u] += sz[v];
            if(son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }
}

int top[MAXN], dfn[MAXN], rnk[MAXN], timer;

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++timer;
    rnk[timer] = u;
    if(son[u] == -1) return;
    dfs2(son[u], t);
    for(auto v : graph[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int bit[1 << MAXC];
void modify(int val, int k) {
    for(; k < 1 << MAXC; k += k & -k) bit[k] ^= val;
}
int query(int k) {
    int ret = 0;
    for(; k > 0; k -= k & -k) ret ^= bit[k];
    return ret;
}
// solution
void solve() {
    int m, c, n; 
    cin >> m >> c >> n;
    for(int i = 0; i < c; ++i) {
        cin >> p[i];
    }
    for(int i = 0; i < 1 << c; ++i) {
        if(i == 0) {
            points[i] = 0;
            continue;
        }
        int k = __lg(i);
        if(1 << k == i) {
            points[i] = p[k];
            continue;
        }
        points[i] = __gcd(points[i ^ (1 << k)], p[k]); 
    }
    for(int i = 0; i < 1 << c; ++i) {
        debug(i, points[i]);
    }
    fwt(points, 1 << c, 1);
    
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int player = 0;
        for(int j = 0; j < x; ++j) {
            int temp;
            cin >> temp;
            player |= 1 << temp;
        }
        ++times[player];
    }
    for(int i = 0; i < 1 << c; ++i) {
        debug(i, times[i]);
    }
    fwt(times, 1 << c, 1);
    safe();
    for(int i = 0; i < 1 << c; ++i) {
        sum[i] = times[i] * points[i] % MOD;
    }
    fwt(sum, 1 << c, INV2);
    for(int i = 0; i < 1 << c; ++i) {
        debug(i, sum[i]);
    }
    safe();
    for(int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs1(0);
    dfs2(0, 0);
    for(int i = 0; i < n; ++i) {
        modify(1 << color[i], dfn[i]);
    }
    for(int i = 0; i < n; ++i) {
        debug(i, dfn[i], color[i], query(dfn[i]));
    }
    int q = 0;
    for(int i = 0; i < m; ++i) {
        int u, v, w, y;
        cin >> u >> v >> w >> y;
        debug(u, v);
        while(top[u] != top[v]) {
            debug(u, v);
            if(dep[top[u]] > dep[top[v]]) swap(u, v);
            q ^= query(dfn[v]) ^ query(dfn[top[v]] - 1);
            v = fa[top[v]];
        }
        if(dep[u] > dep[v]) swap(u, v);
        debug(u, v);
        debug(query(dfn[v]) ^ query(dfn[u] - 1));
        q ^= query(dfn[v]) ^ query(dfn[u] - 1);
        debug(q);
        modify(1 << color[w], dfn[w]);
        color[w] = y;
        modify(1 << color[w], dfn[w]);
        cout << sum[q] % MOD << " \n"[i == m - 1];
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

