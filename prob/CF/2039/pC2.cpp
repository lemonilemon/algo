/*
 * Created : 2024-11-23 23:05:37 lemonilemon
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
ll count_not_avail(ll x, ll m) {
    ll cnt = 0;
    ll curval = 0;
    for (ll i = __lg(m); i >= 0; --i) {
        bool flip = (m >> i) & 1;
        if (flip) {                                  // can flip the bit
            curval += (x & (1ll << i)) ^ (1ll << i); // flip the bit
        } else {                                     // can't flip the bit
            ll curl = curval + ((x & (1ll << i)) ^ (1ll << i)) - 1,
               curr = curl + (1ll << i); // (curl, curr]
            cnt += curr / x - curl / x;
            curval += (x & (1ll << i)); // don't flip
        }
    }
    return cnt;
}
// solution
void solve() {
    ll x, m;
    cin >> x >> m;
    ll cnt = 0;
    for (ll d = 0; d < (1ll << (__lg(x) + 2)); ++d) { // divisible by y
        ll y = x ^ d;
        if (!y || y > m)
            continue;
        if (d % y == 0)
            ++cnt;
    }
    if (m >= x) { // divisible by x
        cnt += ((1ll << (__lg(m) + 1)) - 1) / x;
        cnt -= count_not_avail(x, m);
    }
    for (ll d = 0; d < (1ll << (__lg(x) + 2)); ++d) { // divisible by x * y
        ll y = x ^ d;
        if (!y || y > m)
            continue;
        if (d % (x * y) == 0)
            --cnt;
    }
    cout << cnt << '\n';
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
