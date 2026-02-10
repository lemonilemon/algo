/*
 * Created : 2026-02-08 16:21:29 lemonilemon
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

// solution
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    map<int, int> freq;
    ll ans = 0;
    for (int l = 0, r = -1; l < n; ++l) {
        while (r < l) {
            ++freq[a[++r]];
        }
        while (r < n - 1 &&
               (freq.lower_bound(a[r + 1]) == freq.end() ||
                abs(freq.lower_bound(a[r + 1])->first - a[r + 1]) >= d) &&
               (freq.lower_bound(a[r + 1]) == freq.begin() ||
                abs(prev(freq.lower_bound(a[r + 1]))->first - a[r + 1]) >= d)) {
            ++freq[a[++r]];
        }
        ans += r - l + 1;
        debug(l, r);
        --freq[a[l]];
        if (freq[a[l]] == 0)
            freq.erase(a[l]);
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
