/* 
 * Created : 2024-08-31 00:04:16 lemonilemon
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
int p[MAXN];
vector<int> child[MAXN];
int r[MAXN];
int cnt[MAXN];
int dfs(int u, int pa = -1) {
    r[u] = u;
    for(auto v : child[u]) {
        if(v == pa) continue;
        r[u] = max(dfs(v, u), r[u]);
    }
    if(~pa) {
        ++cnt[r[u]];
        ++cnt[u - 1];
    }
    return r[u];
}

// solution
void solve() {
    int n;
    ll w;
    cin >> n >> w;
    for(int i = 1; i <= n; ++i) {
        cnt[i] = 0;
        child[i].clear();
    }
    for(int i = 2; i <= n; ++i) {
        cin >> p[i];
        child[p[i]].push_back(i);
    }
    dfs(1);
    ll uncertaincnt = n;
    ll certain = 0;
    for(int i = 1; i <= n - 1; ++i) {
        int x;
        ll y;
        cin >> x >> y;
        w -= y;
        certain += y;
        --cnt[r[x]];
        if(cnt[r[x]] == 0) --uncertaincnt;
        certain += y;
        --cnt[x - 1];
        if(cnt[x - 1] == 0) --uncertaincnt; 
        /*debug(cnt[r[x]], cnt[x - 1]);
        debug(certain, uncertaincnt);*/
        ll ans = certain + uncertaincnt * w;
        cout << ans << " \n"[i == n - 1];
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

