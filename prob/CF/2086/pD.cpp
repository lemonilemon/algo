/*
 * Created : 2025-04-19 01:19:22 lemonilemon
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
const int MAXA = 26;
const ll MAXSUMC = 5e5 + 5;
const int MOD = 998244353;
int mabs(ll x) { return (x % MOD + MOD) % MOD; }
int madd(int x, int y) { return mabs(x + y); }
int mmul(int x, int y) { return mabs(1ll * x * y); }
int c[MAXA];
int dp[2][MAXSUMC];
int fact[MAXSUMC];
int invfact[MAXSUMC];
int fastpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int inv(int x) { return fastpow(x, MOD - 2); }
// solution
void init() {
    invfact[0] = fact[0] = 1;
    for (int i = 1; i < MAXSUMC; ++i) {
        fact[i] = mmul(fact[i - 1], i);
        invfact[i] = inv(fact[i]);
    }
}
void solve() {
    ll sum = 0;
    for (int i = 0; i < 26; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 0; i <= (sum >> 1); ++i) {
        dp[0][i] = dp[1][i] = 0;
    }
    dp[1][0] = 1;
    for (int i = 0; i < 26; ++i) {
        int cur = i & 1;
        int last = cur ^ 1;
        for (int j = 0; j < c[i]; ++j) {
            dp[cur][j] = dp[last][j];
        }
        for (int j = c[i]; j <= (sum >> 1); ++j) {
            if (c[i] > 0)
                dp[cur][j] = madd(dp[last][j - c[i]], dp[last][j]);
            else
                dp[cur][j] = dp[last][j];
        }
    }
    int even = sum >> 1;
    int odd = sum - even;
    int ans = mmul(fact[odd], fact[even]);
    debug(even, odd, ans, fact[odd], fact[even]);
    for (int i = 0; i < 26; ++i) {
        ans = mmul(ans, invfact[c[i]]);
    }
    debug(ans, dp[1][even], dp[1][odd]);
    ans = mmul(ans, dp[1][even]);
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
