/* 
 * Created : 2024-10-26 23:13:46 lemonilemon
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
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const ll INF = 1e18 + 7;
const int MOD = 1e9 + 7;
int mabs(ll x) { return (x % MOD + MOD) % MOD; }
ll a[MAXN], b[MAXM];
ll pre[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    vector<vector<ll> > dp(n + 1, vector<ll>(m + 1, INF));
    vector<vector<ll> > dp2(n + 1, vector<ll>(m + 1, 0));
    for(int i = 0; i <= m; ++i) {
        dp[0][i] = 0;
        dp2[0][i] = 1;
    }
    for(int j = 1; j <= m; ++j) {
        ll tot = 0;
        vector<ll> predp2(1, 1);
        for(int i = 1; i <= n; ++i) {
            dp[i][j] = dp[i][j - 1];
            dp2[i][j] = dp2[i][j - 1];
            tot += a[i];
            int best_i = (lower_bound(pre, pre + i, tot - b[j]) - pre);
            if(best_i != i) {
                if(dp[i][j] >= dp[best_i][j] + m - j) {
                    int l = best_i, r = i;
                    while(r - l > 1) {
                        int mid = (l + r) >> 1;
                        if(dp[mid][j] > dp[best_i][j]) r = mid;
                        else l = mid;
                    }
                    ll tmp = dp2[i][j];
                    dp2[i][j] = predp2[l] - (best_i > 0? predp2[best_i - 1] : 0);
                    if(dp[i][j] == dp[best_i][j] + m - j) dp2[i][j] += tmp;
                    dp[i][j] = dp[best_i][j] + m - j;
                } 
            }
            // debug(i, j, best_i, dp[i][j]);
            dp2[i][j] = mabs(dp2[i][j]);
            predp2.push_back(mabs(dp2[i][j] + predp2.back()));
            // debug(i, j, dp[i][j]);
        }
    }
    if(dp[n][m] >= INF) cout << "-1\n";
    else cout << dp[n][m] << ' ' << dp2[n][m] << '\n';
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
