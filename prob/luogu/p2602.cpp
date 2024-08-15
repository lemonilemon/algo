/* 
 * Created : 2024-08-15 14:29:55 lemonilemon
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

int dig[18];
ll p[18], now[18];
ll dp[18];

ll dfs(int u, int d, bool f0, bool lim) { // x: which decimal
    if(!u) return 0;
    if(!lim && !f0 && (~dp[u])) return dp[u];
    int lst = lim? dig[u] : 9;
    ll cnt = 0;
    for(int i = 0; i <= lst; ++i) {
        if(f0 && i == 0) {
            cnt += dfs(u - 1, d, 1, lim && i == lst);
        } else if(i == d && lim && i == lst) {
            cnt += now[u - 1] + 1 + dfs(u - 1, d, 0, lim && i == lst);
        } else if(i == d) {
            cnt += p[u - 1] + dfs(u - 1, d, 0, lim && i == lst);
        } else {
            cnt += dfs(u - 1, d, 0, lim && i == lst);
        }
    }
    if(!lim && !f0) dp[u] = cnt;
    return cnt;

}
ll ans(ll x, int d) {
    int len = 0;
    for(int i = 0; i < 18; ++i) {
        dp[i] = -1;
    }
    while(x) {
        dig[++len] = x % 10; 
        x /= 10;
        now[len] = now[len - 1] + dig[len] * p[len - 1];
    }
    return dfs(len, d, 1, 1);
}

// solution
void solve() {
    ll a, b;
    cin >> a >> b;


    p[0] = 1;
    for(int i = 1; i < 18; ++i) {
        p[i] = p[i - 1] * 10;
    }
    for(int i = 0; i < 10; ++i) {
        cout << ans(b, i) - ans(a - 1, i) << " \n"[i == 9];
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

