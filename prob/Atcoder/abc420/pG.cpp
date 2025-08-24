/*
 * Created : 2025-08-24 21:26:15 lemonilemon
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

// solution
void solve() {
    ll x;
    cin >> x;
    // n^2 + n + x = m^2 <=> 4n^2 + 4n + 4x = 4m^2
    // <=> (2n+1)^2 + 4x - 1 = (2m)^2
    // <=> (2m + 2n + 1)(2m - 2n - 1) = 4x - 1
    vector<ll> ans;
    for (ll a = -(int)(1e7 + 5); a < (int)(1e7 + 5); ++a) {
        if (a == 0)
            continue;
        if ((4 * x - 1) % a != 0)
            continue;
        ll b = (4 * x - 1) / a;
        if ((a + b) % 4 == 0 && (a - b - 2) % 4 == 0) {
            ll m = (a + b) / 4;
            ll n = (a - b - 2) / 4;
            ans.push_back(n);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
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
