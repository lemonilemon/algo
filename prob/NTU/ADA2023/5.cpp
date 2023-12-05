/* 
 * Created : 2023-12-05 04:04:42 lemonilemon
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
const int MAXN = 1e6 + 5, MAXM = 1e6 + 5;
tuple<ll, int, int> edge[MAXM];
struct DSU {
    int sz;
    int rt[MAXN], rk[MAXN];
    DSU(int sz): sz(sz) {
        for(int i = 1; i <= sz; ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
    int findroot(int k) {
        return rt[k] == k? k : rt[k] = findroot(rt[k]);
    }
    bool setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if(r1 == r2) return 0;
        if(rk[r1] > rk[r2]) {
            rt[r2] = r1;
            rk[r1] += rk[r2];
        } else {
            rt[r1] = r2;
            rk[r2] += rk[r1];
        }
        return 1;
    }
};

// solution
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; ++i) {
        auto& [w, u, v] = edge[i];
        cin >> u >> v >> w;
    }
    sort(edge, edge + m);
    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        auto [w, u, v] = edge[i];
        if(dsu.setunion(u, v)) ans += w;
    }
    cout << ans << '\n';
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

