/* 
 * Created : 2023-12-09 12:00:29 lemonilemon
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
const int MAXN = 2.5e5 + 5;
ll a[MAXN];
ll p[MAXN];
ll layer[MAXN];
vector<int> child[MAXN];
bool color[MAXN];
int d[MAXN];
void dfs(int u = 1, int depth = 0) {
    color[u] = 1;
    d[u] = depth;
    for(auto v : child[u]) {
        dfs(v, depth + 1);
    }
}
struct DSU {
    int sz;
    int rt[MAXN], rk[MAXN];
    DSU(int _sz): sz(_sz) {
        for(int i = 1; i <= sz; ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
    int findroot(int k) {
        return rt[k] == k? k : rt[k] = findroot(rt[k]);
    }
    void setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if(r1 == r2) return;
        if(rk[r1] > rk[r2]) {
            rt[r2] = r1;
            rk[r1] += rk[r2];
        } else {
            rt[r1] = r2;
            rk[r2] += rk[r1];
        }
    }
};
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 2; i <= n; ++i) {
        cin >> p[i];
        child[p[i]].push_back(i);
    }
    dfs();
    DSU dsu(n);
    layer[0] += a[1];
    for(int i = 2; i <= n; ++i) {
        if(!color[i]) continue;
        dsu.setunion(i, p[i]);
        layer[d[i]] += a[i];
        if(dsu.findroot(1) != dsu.findroot(i)) layer[d[i] - 1] -= a[i];
    }
    for(int i = n; i >= 0; --i) {
        if(layer[i] > 0) {
            cout << "+\n";
            return;
        } else if(layer[i] < 0) {
            cout << "-\n";
            return;
        }
    }
    cout << "0\n";
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

