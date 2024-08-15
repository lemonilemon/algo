/* 
 * Created : 2024-08-13 17:56:12 lemonilemon
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
const int MAXD = 19;
ll dp[MAXD], p[MAXD];
int dig[MAXD];



void init() {
    p[0] = 1;
    for(int i = 1; i < MAXD; ++i) {
        p[i] = p[i - 1] * 10;
    }
}
ll dfs(int u, int last, bool f0, bool lim) {
    if(!u) return 1;
    if(!f0 && !lim && (~dp[u])) return dp[u];
    ll lst = lim? dig[u] : 9;
    ll ret = 0;
    for(int i = 0; i <= lst; ++i) {
        if(f0 && i == 0) {
            ret += dfs(u - 1, i, 1, lim && i == lst);
            continue;
        }
        if(i == last) continue;
        ret += dfs(u - 1, i, 0, lim && i == lst);
    }
    if(!f0 && !lim) dp[u] = ret;
    return ret;
}
ll getans(ll x) {
    int len = 0;
    while(x) { 
        dig[++len] = x % 10;
        x /= 10;
    }
    for(int i = 0; i <= len; ++i) {
        dp[i] = -1;
    }
    return dfs(len, 0, 1, 1);
}
// solution
void solve() {
    ll a, b;
    cin >> a >> b;
    cout << getans(b) - getans(a - 1) << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    init();
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

