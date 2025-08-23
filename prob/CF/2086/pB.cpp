/*
 * Created : 2025-04-19 00:16:27 lemonilemon
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
const int MAXN = 1e5 + 5;
ll presum[MAXN];
// solution
void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    ll sum = 0;
    presum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> presum[i];
        sum += presum[i];
        presum[i] += presum[i - 1];
    }
    ll need = x / sum;
    ll left = x - need * sum;
    if (k < need) {
        cout << "0\n";
        return;
    }
    if (left == 0) {
        cout << n * (k - need) + 1 << '\n';
        return;
    }
    int y = upper_bound(presum + 1, presum + n + 1, sum - left) - presum;
    cout << max(y + (k - need - 1) * n, 0ll) << '\n';
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
