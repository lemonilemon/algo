/*
 * Created : 2026-02-10 22:01:43 lemonilemon
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
const int MAXK = 365;
ll dp[2][MAXK][MAXK];
// solution
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> inc;
    for (int i = 1; i <= n; ++i) {
        if (inc.empty() || a[i] > inc.back().first) {
            inc.push_back({a[i], i});
        }
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[0][i][j] = dp[1][i][j] = 0;
        }
    }
    for (int i = 0; i < inc.size(); ++i) {
        int cur = i & 1;
        int last = !cur;
        auto [mxval, idx] = inc[i];
        // not take
        for (int j = 0; j <= k; ++j) {
            for (int h = 0; h <= k; ++h) {
                dp[cur][j][h] = dp[last][j][h];
            }
        }
        ll mxans = 0;
        ll mxh, mxj;
        for (int spent = 0; spent <= k; ++spent) {

            ll bestval = 0;
            // take
            for (int h = 0; spent + h <= k && h <= mxval; ++h) {
                int j = spent + h;
                bestval =
                    max(bestval, dp[last][spent][h] - 1ll * h * (n - idx + 1));
                dp[cur][j][h] =
                    max(dp[cur][j][h], bestval + 1ll * h * (n - idx + 1));
                debug(i, j, h, dp[cur][j][h], bestval);
            }
        }
    }
    int last = ((int)inc.size() - 1) & 1;
    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            ans = max(ans, dp[last][i][j]);
        }
    }
    cout << ans << '\n';
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
