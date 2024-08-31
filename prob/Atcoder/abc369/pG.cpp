/* 
 * Created : 2024-08-31 22:38:22 lemonilemon
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
ll dep[MAXN], fal[MAXN];
int fa[MAXN], tl[MAXN], tr[MAXN], timer;
int tl2idx[MAXN];
ll seg[MAXN << 2], idx[MAXN << 2];
ll lazy[MAXN << 2];
bool color[MAXN];
vector<pair<int, ll> > graph[MAXN];
void dfs(int u = 1, int pa = -1) {
    fa[u] = pa;
    tl[u] = ++timer;
    tl2idx[tl[u]] = u;
    for(auto [v, w] : graph[u]) {
        if(v == pa) continue;
        dep[v] = dep[u] + w;
        fal[v] = w;
        dfs(v, u);
    }
    tr[u] = timer;
}
void pull(int v) {
    if(seg[v << 1] > seg[v << 1 | 1]) {
        seg[v] = seg[v << 1];
        idx[v] = idx[v << 1];
    } else {
        seg[v] = seg[v << 1 | 1];
        idx[v] = idx[v << 1 | 1];
    }
}
void tag(int v, ll val) {
    seg[v] += val;
    lazy[v] += val;
}
void push(int v) {
    if(lazy[v]) {
        tag(v << 1, lazy[v]);
        tag(v << 1 | 1, lazy[v]);
        lazy[v] = 0;
    }
}
void build(int l, int r, int v) {
    if(l == r) {
        idx[v] = tl2idx[l];
        seg[v] = dep[idx[v]];
        lazy[v] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
void modify(ll val, int ql, int qr, int l, int r, int v) {
    if(ql == l && qr == r) {
        tag(v, val);
        return;
    }
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) modify(val, ql, qr, l, mid, v << 1);
    else if(ql > mid) modify(val, ql, qr, mid + 1, r, v << 1 | 1);
    else {
        modify(val, ql, mid, l, mid, v << 1);
        modify(val, mid + 1, qr, mid + 1, r, v << 1 | 1);
    }
    pull(v);
}
pair<ll, int> query(int ql, int qr, int l, int r, int v) {
    if(ql == l && qr == r) return { seg[v], idx[v] };
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    else if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    else {
        return max(query(ql, mid, l, mid, v << 1),
            query(mid + 1, qr, mid + 1, r, v << 1 | 1));
    }
}

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dfs(); 
    build(1, n, 1);
    color[1] = 1;
    ll ans = 0;
    for(int k = 1; k <= n; ++k) {
        /*for(int i = 1; i <= n; ++i) {
            auto tmp = query(tl[i], tl[i], 1, n, 1);
            debug(i, tmp.first, tmp.second);
        }*/
        int cur = idx[1];
        ans += seg[1] << 1;
        while(!color[cur]) {
            color[cur] = 1;
            modify(-fal[cur], tl[cur], tr[cur], 1, n, 1);
            cur = fa[cur];
        }
        
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


