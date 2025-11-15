/*
 * Created : 2025-11-15 20:03:16 lemonilemon
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
const int MAXN = 2e5 + 5;
int a[MAXN];
// solution
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int div = y - x;
    int mn = 1e9 + 7;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int total_remainder = (1ll * mn * x) % div;
    for (int i = 0; i < n; ++i) {
        if ((1ll * a[i] * x) % div != total_remainder) {
            cout << -1 << '\n';
            return;
        }
        if ((1ll * a[i] * y) % div != total_remainder) {
            cout << -1 << '\n';
            return;
        }
    }
    if (1ll * mn * y < 1ll * mx * x) {
        cout << "-1\n";
        return;
    }
    ll total = 1ll * y * mn;
    ll ans = 0;
    debug(total, div);
    for (int i = 0; i < n; ++i) {
        ans += (total - 1ll * a[i] * x) / div;
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
