/* 
 * Created : 2023-09-02 20:48:12 lemonilemon
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
#endif

// constants
const int MAXN = 17;
int n;
bool color[MAXN];
ll d[MAXN][MAXN];
ll dfs(int u = 1, ll cur = 0) {
    if(u > n) return cur;
    if(color[u]) return dfs(u + 1, cur);
    color[u] = 1;
    ll ret = 0;
    for(int v = u + 1; v <= n; ++v) {
        if(!color[v]) {
            color[v] = 1;
            ll val = cur + d[u][v];
            ret = max(ret, dfs(u + 1, val)); 
            color[v] = 0;
        }
    }
    ret = max(ret, dfs(u + 1, cur));
    color[u] = 0;
    return ret;
}

// solution
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            cin >> d[i][j];
        } 
    }
    cout << dfs() << '\n';
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

