/*
 * Created : 2024-11-11 10:25:27 lemonilemon
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
const int MAXN = 505;
const int MAXM = 505;
const int MOD = 1e9 + 7;
int x[MAXN], v[MAXM];
int mabs(ll a) { return (a % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmul(int a, int b) { return mabs(1LL * a * b); }
int fastpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int inv(int a) { return fastpow(a, MOD - 2); }
int dp[MAXM];
int cnt[MAXM];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= m; ++i) {
        dp[i] = 0;
        cnt[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        x[i] = -x[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    vector<pair<int, int> > combo;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            combo.push_back({i, j});
        }
    }
    sort(combo.begin(), combo.end(), [](auto a, auto b) {
        return 1ll * x[a.first] * v[b.second] < 1ll * x[b.first] * v[a.second];
    });
    int ans = 0;
    for(auto [i, j] : combo) { // x[i] / v[j] is the median
        int t = mmul(x[i], inv(v[j]));
        // divide (q + px)
        // debug(x[i], v[j]);
        // debug(cnt[j]);
        int p = mmul(cnt[j], inv(n));
        int q = madd(1, -p);
        int qinv = inv(q);
        // debug(p, q, qinv);
        for(int k = 0; k <= m / 2; ++k) {
            dp[k] = mmul(dp[k], qinv);
            // debug(i, j, k, dp[k]);
        }
        int frac = mmul(-p, qinv);
        // debug(frac);
        int sum = 0;
        for(int k = 0; k <= m / 2; ++k) {
            sum = mmul(sum, frac);
            sum = madd(sum, dp[k]);
            dp[k] = sum;
            // debug(i, j, k, dp[k]);
        }
        ans = madd(ans, mmul(t, mmul(dp[m >> 1], inv(n))));

        // multiply (q' + p'x)
        ++cnt[j];
        p = mmul(cnt[j], inv(n));
        q = madd(1, -p);
        for(int k = m / 2; k >= 0; --k) {
            dp[k] = madd(mmul(q, dp[k]), k > 0? mmul(p, dp[k - 1]) : 0);
            // debug(i, j, k, dp[k]);
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
