/* 
 * Created : 2024-09-21 10:03:02 lemonilemon
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
const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int timer;
int tl[MAXN], tr[MAXN], hc[MAXN], par[MAXN];
int tp[MAXN];
int sz[MAXN], dep[MAXN];

void dfs(int u, int pa = -1) {
    sz[u] = 1;
    hc[u] = 0;
    if(~pa) dep[u] = dep[pa] + 1;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[hc[u]]) hc[u] = v;
    } 
}
void chain(int u, int top) {
    tl[u] = ++timer;
    tp[u] = top;
    if(hc[u]) chain(hc[u], top);
    for(auto v : graph[u]) {
        if(v == par[u] || v == hc[u]) continue;
        chain(v, v);
    }
    tr[u] = timer;
}
ll bit[MAXN];
void modify(ll x, int k) {
    for(; k < MAXN; k += k & -k) bit[k] += x;
}
ll query(int k) {
    ll res = 0;
    for(; k; k -= k & -k) res += bit[k];
    return res;
}


// solution
void solve() {
    int n, q;
    cin >> n >> q;
    par[1] = -1;
    for(int i = 2; i <= n; ++i) {
        cin >> par[i];
        graph[par[i]].push_back(i);
    }
    dfs(1);
    chain(1, 1);
    for(int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        switch(op) {
            case 1: {
                int u, c;
                cin >> u >> c;
                modify(c, tl[u]);
                break;
            }
            case 2: {
                int u, v;
                cin >> u >> v;
                ll ans = 0;
                while(tp[u] != tp[v]) {
                    if(dep[tp[u]] < dep[tp[v]]) swap(u, v);
                    ans += query(tl[u]) - query(tl[tp[u]] - 1);
                    u = par[tp[u]];
                }
                if(dep[u] < dep[v]) swap(u, v);
                ans += query(tl[u]) - query(tl[v] - 1);
                cout << ans << '\n';
                break;
            }
            case 3: {
                int u;
                cin >> u;
                cout << query(tr[u]) - query(tl[u] - 1) << '\n';
                break;
            }
                   
        }
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

