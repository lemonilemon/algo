/*
 * Created : 2025-01-01 18:31:22 lemonilemon
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
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 5005;
const ll INF = 1e18;
ll dp[MAXN];
ll cost[MAXN];
int c[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    cost[0] = 0;
    cost[1] = 1;
    for (int i = 2; i <= n; ++i) {
        cost[i] = cost[i - 1] + ((i + 1) >> 1);
        // debug(i, cost[i]);
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = (i * (i - 1) >> 1) + c[i];
        for (int j = 1; j < i; ++j) {
            ll dis = i - j - 1;
            dp[i] = min(dp[j] + cost[dis] + c[i], dp[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll right = n - i;
        dp[i] += right * (right + 1) >> 1;
        // debug(i, dp[i]);
    }
    ll ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
