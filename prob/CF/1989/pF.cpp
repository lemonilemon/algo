/* 
 * Created : 2024-09-14 11:09:53 lemonilemon
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
const int MAXN = 4e5 + 5;
const int MAXQ = 2e5 + 5;
ll ans[MAXQ];
vector<int> graph[MAXN], rgraph[MAXN];
vector<pair<int, int> > edges;

ll getcost(int x) {
    return x > 1? 1ll * x * x : 0;
}
ll currentsum;
int scc[MAXN];
struct DSU {
    ll n, rk[MAXN], rt[MAXN]; 
    vector<ll*> where;
    vector<ll> oldval;
    DSU() {}
    void init(int sz) {
        n = sz;
        for(int i = 0; i <= n; ++i) {
            rk[i] = 1;
            rt[i] = i;
        }
    }
    DSU(int sz): n(sz) {
        for(int i = 0; i <= n; ++i) {
            rk[i] = 1;
            rt[i] = i;
        }
    }
    int findroot(int k) {
        return k == rt[k]? k : findroot(rt[k]);
    }
    bool setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if(r1 == r2) return 0;
        if(scc[r1] != scc[r2]) return 0;
        where.push_back(&currentsum);
        oldval.push_back(currentsum);
        currentsum -= getcost(rk[r1]) + getcost(rk[r2]);
        if(rk[r1] > rk[r2]) swap(r1, r2); 
        where.push_back(&rk[r2]);
        oldval.push_back(rk[r2]);
        rk[r2] += rk[r1];
        currentsum += getcost(rk[r2]);
        where.push_back(&rt[r1]);
        oldval.push_back(rt[r1]);
        rt[r1] = r2;
        return 1;
    }
} dsu;


vector<int> ord;
bool color[MAXN];
void dfs(int u) {
    color[u] = 1;
    for(auto v : graph[u]) {
        if(color[v]) continue;
        dfs(v);
    }
    ord.push_back(u);
}
void rdfs(int u, int k) {
    scc[u] = k;
    for(auto v : rgraph[u]) {
        if(scc[v]) continue;
        rdfs(v, k);
    }
}

void rec(int l, int r, const vector<int>& ids) {
    if(l == r - 1) {
        ans[l] = currentsum;
        return;
    }
    int mid = (l + r) >> 1;
    for(auto id : ids) {
        if(id >= mid) continue;
        auto [u, v] = edges[id];
        u = dsu.findroot(u);
        v = dsu.findroot(v);
        for (auto w : {u, v}) if (color[w]){
			graph[w].clear();
			rgraph[w].clear();
            scc[w] = 0;
            color[w] = 0;
		}
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    ord.clear();
    for(auto id : ids) {
        if(id >= mid) continue;
        auto [u, v] = edges[id];
        u = dsu.findroot(u);
        v = dsu.findroot(v);
        for(auto w : {u, v}) {
            if(color[w]) continue;
            dfs(w);
        }
    }
    reverse(ord.begin(), ord.end());
    int scccnt = 0;
    for(auto u : ord) {
        if(!scc[u]) rdfs(u, ++scccnt);
    }
    int t = dsu.oldval.size(); // timestamp
    for(auto id : ids) {
        if(id >= mid) continue;
        auto [u, v] = edges[id];
        dsu.setunion(u, v);
    }
    vector<int> tl, tr;
    for(auto id : ids) {
        if(id >= mid) {
            tr.push_back(id);
            continue;
        }
        auto [u, v] = edges[id];
        if(dsu.findroot(u) == dsu.findroot(v)) tl.push_back(id);
        else tr.push_back(id);
    }
    rec(mid, r, tr);
    while(dsu.oldval.size() > t) {
        *dsu.where.back() = dsu.oldval.back();
        dsu.where.pop_back();
        dsu.oldval.pop_back();
    }
    rec(l, mid, tl);
}

// solution
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    dsu.init(n + m);
    for(int i = 0; i < q; ++i) {
        int r, c;
        char ch;
        cin >> r >> c >> ch;
        c += n;
        if(ch == 'R') edges.push_back({c, r});
        else edges.push_back({r, c});
    }
    vector<int> ids(q);
    iota(ids.begin(), ids.end(), 0);
    rec(0, q + 1, ids);
    for(int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
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

