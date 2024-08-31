/* 
 * Created : 2024-08-31 20:34:02 lemonilemon
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
const ll INF = 1e18 + 7;
int a[MAXN];
ll dp[MAXN][2];


// solution
void solve() {
    int n; 
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i];
    dp[0][0] = 0;
    dp[0][1] = -INF;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 2 * a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';

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

