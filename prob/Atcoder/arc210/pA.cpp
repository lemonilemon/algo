/*
 * Created : 2025-11-16 19:55:44 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

// Docs for AC-library:
// https://atcoder.github.io/ac-library/production/document_en/
#include <atcoder/all>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace atcoder;
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

// using mint = modint;
// using mint = modint1000000007;
// using mint = modint998244353;
// constants

// solution
const int MAXN = 2e5 + 5;
ll current_dif[MAXN];
ll mn_dif[MAXN];
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; ++i) {
        mn_dif[i] = 0;
    }
    for (int i = 0; i < q; ++i) {
        int idx, x;
        cin >> idx >> x;
        current_dif[idx] += x;
        mn_dif[idx] = min(mn_dif[idx], current_dif[idx]);
        current_dif[idx + 1] -= x;
        mn_dif[idx + 1] = min(mn_dif[idx + 1], current_dif[idx + 1]);
    }
    ll ans = 0;
    ll current_val = 0;
    for (int i = 1; i <= n; ++i) {
        current_val += -mn_dif[i] + 1;
        ans += current_val;
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
