/* 
 * Created : 2024-08-21 11:01:14 lemonilemon
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
const int MAXN = 505, MAXM = 505;
inline int mabs(ll a, int p) {
    return a % p;
}
inline int madd(int a, int b, int p) {
    return mabs(a + b, p);
}
inline int mmul(int a, int b, int p) {
    return mabs(1ll * a * b, p);
}
int dp[2][MAXN][MAXM];

// solution
void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            dp[0][i][j] = dp[1][i][j] = 0;
        }
    }
    dp[0][0][0] = dp[1][0][0] = 1;
    for(int i = 0; i <= k; ++i) {
        dp[0][1][i] = dp[1][1][i] = 1;
    }
    for(int i = 2; i <= n; ++i) {
        dp[0][i][0] = 0;
        dp[1][i][0] = 1;
        for(int j = 1; j <= k; ++j) {
            dp[0][i][j] = dp[0][i][j - 1];
            dp[1][i][j] = dp[1][i][j - 1];
            for(int l = 0; l <= j; ++l) {
                int r = j - l;
                if(l > r)
                    dp[0][i][j] = madd(dp[0][i][j], mmul(dp[0][i - 1][l], dp[1][i - 1][r], p), p);
                else if(r > l)
                    dp[0][i][j] = madd(dp[0][i][j], mmul(dp[1][i - 1][l], dp[0][i - 1][r], p), p);
                dp[1][i][j] = madd(dp[1][i][j], mmul(dp[1][i - 1][l], dp[1][i - 1][r], p), p);
            }
        }
    }
    cout << dp[0][n][k] << '\n';
    
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

