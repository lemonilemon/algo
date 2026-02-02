/*
 * Created : 2025-11-29 18:31:46 lemonilemon
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
const int MOD = 998244353;
int mabs(ll x) { return (x % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmul(int a, int b) { return mabs(1LL * a * b); }
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ranges(m);
    vector<int> dp(n + 2, 0); // number of ways of available transition with
                              // last transition ends at i
    vector<int> prefix_dp(n + 2, 0);
    dp[0] = 1;
    prefix_dp[0] = 1;
    for (auto &[l, r] : ranges) {
        cin >> l >> r;
        ++l;
    }
    sort(ranges.begin(), ranges.end(),
         [](auto &a, auto &b) { return a.second < b.second; });
    int cur_range = 0;
    int mxl = 0;
    for (int r = 1; r <= n + 1; ++r) {
        while (cur_range < m && ranges[cur_range].second < r) {
            mxl = max(mxl, ranges[cur_range].first);
            ++cur_range;
        }
        if (mxl == 0) {
            dp[r] = prefix_dp[r - 1];
        } else {
            dp[r] = mabs(prefix_dp[r - 1] - prefix_dp[mxl - 1]);
        }
        prefix_dp[r] = mabs(prefix_dp[r - 1] + dp[r]);
    }
    cout << dp[n + 1] << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
