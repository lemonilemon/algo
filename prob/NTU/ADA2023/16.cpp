/* 
 * Created : 2023-10-17 06:25:49 lemonilemon
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
const int MAXN = 1e7 + 5, INF = 1e9 + 7;
bool mat[3][MAXN];
ll dp[3][MAXN][3]; // 0 : not planted, 1 : planted, 2 : special

// solution
void solve() {
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < 3; ++i) {
        for(ll j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            mat[i][j] = ch == '.';
        }
    }
    for(ll j = 1; j <= n; ++j) {
        for(ll i = 0; i < 3; ++i) {
            dp[i][j][0] = max({dp[i][j - 1][0], dp[i][j - 1][1], dp[i][j - 1][2]});
            dp[i][j][1] = -INF;
            dp[i][j][2] = -INF;
            if(mat[i][j]) {
                for(ll r = 0; r < 3; ++r) {
                    ll left2 = k - (i - r) * (i - r);
                    ll left = ceil(sqrt(left2));
                    ll c = j - left;
                    if(c < 0) dp[i][j][1] = 1;
                    else if(k == 5) {
                        dp[i][j][1] = max(dp[i][j][1], dp[r][c][0] + 1);
                        if(abs(i - r) == 2 && dp[r][c][1] >= 0) dp[i][j][2] = dp[r][c][1] + 1;
                        else dp[i][j][1] = max({dp[i][j][1], dp[r][c][1] + 1, dp[r][c][2] + 1});
                    } else dp[i][j][1] = max(dp[i][j][1], max({dp[r][c][0], dp[r][c][1], dp[r][c][2]}) + 1);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            ans = max(ans, dp[i][n][j]);
        }
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

