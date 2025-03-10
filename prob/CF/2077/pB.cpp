/*
 * Created : 2025-03-10 23:45:02 lemonilemon
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
int cnt[30];
// solution
void solve() {
    int ask1 = 0; // even
    for (int i = 0; i < 15; ++i) {
        ask1 <<= 2;
        ++ask1;
    }
    cout << ask1 << endl;
    cout.flush();
    ll ans1;
    cin >> ans1;
    int ask2 = 0; // odd
    for (int i = 0; i < 15; ++i) {
        ask2 <<= 2;
        ask2 += 2;
    }
    cout << ask2 << endl;
    cout.flush();
    ll ans2;
    cin >> ans2;
    ll evensum, oddsum;
    oddsum = ans1 - ask2;
    evensum = ans2 - (ask1 << 2);
    // debug(evensum, oddsum);
    // cin >> ans2;
    for (int i = 0; i < 15; ++i) {
        cnt[i << 1] = (evensum >> (i << 1)) & 3;
    }
    for (int i = 0; i < 15; ++i) {
        cnt[i << 1 | 1] = (oddsum >> (i << 1 | 1)) & 3;
    }
    // for (int i = 0; i < 5; ++i) {
    //     cerr << cnt[i] << ' ';
    // }
    // cerr << '\n';
    cout << "!" << endl;
    cout.flush();
    ll m;
    cin >> m;
    ll ans = ((1 << 30) - 1) << 1;
    for (int i = 0; i < 30; ++i) {
        int b = (m >> i) & 1;
        if (b)
            continue;
        ans -= (2 - cnt[i]) << i;
    }
    cout << ans << endl;
    cout.flush();
}

// main
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
