/*
 * Created : 2024-11-15 03:08:23 lemonilemon
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
ll fpow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a, ll m) { return fpow(a, m - 2, m); }

ll trial(ll y, ll z, ll m) {
    ll a0 = 1, a1 = 0, b0 = z, b1 = 1, p = (m - 1) / 2;
    while (p) {
        if (p & 1)
            tie(a0, a1) = make_pair((a1 * b1 % m * y + a0 * b0) % m,
                                    (a0 * b1 + a1 * b0) % m);
        tie(b0, b1) =
            make_pair((b1 * b1 % m * y + b0 * b0) % m, (2 * b0 * b1) % m);
        p >>= 1;
    }
    if (a1)
        return inv(a1, m);
    return -1;
}
mt19937 rd(49);
ll psqrt(ll y, ll p) {
    if (y == 0)
        return 0;
    if (fpow(y, (p - 1) / 2, p) != 1)
        return -1;
    for (int i = 0; i < 30; i++) {
        ll z = rd() % p;
        if (z * z % p == y)
            return z;
        ll x = trial(y, z, p);
        if (x == -1)
            continue;
        return x;
    }
    return -1;
}

// solution
void solve() {
    int y, p;
    cin >> y >> p;
    cout << psqrt(y, p) << '\n';
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
