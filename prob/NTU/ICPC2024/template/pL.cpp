/*
 * Created : 2024-11-15 02:58:27 lemonilemon
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
ll mul(ll a, ll b, ll mod) { return (ll)(__int128(a) * b % mod); }
bool Miller_Rabin(ll a, ll n) {
    if ((a = a % n) == 0)
        return 1;
    if (n % 2 == 0)
        return n == 2;
    ll tmp = (n - 1) / ((n - 1) & (1 - n));
    ll t = __lg(((n - 1) & (1 - n))), x = 1;
    for (; tmp; tmp >>= 1, a = mul(a, a, n))
        if (tmp & 1)
            x = mul(x, a, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (--t)
        if ((x = mul(x, x, n)) == n - 1)
            return 1;
    return 0;
}
vector<ll> base = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool prime(ll n) {
    for (auto &a : base)
        if (!Miller_Rabin(a, n))
            return 0;
    return 1;
}

map<ll, int> cnt;
void PollardRho(ll n) { // O(n^0.25)
    if (n == 1)
        return;
    if (prime(n))
        return ++cnt[n], void();
    if (n % 2 == 0)
        return PollardRho(n / 2), ++cnt[2], void();
    ll x = 2, y = 2, d = 1, p = 1;
#define f(x, n, p) ((mul(x, x, n) + p) % n)
    while (true) {
        if (d != n && d != 1) {
            PollardRho(n / d);
            PollardRho(d);
            return;
        }
        if (d == n)
            ++p;
        x = f(x, n, p), y = f(f(y, n, p), n, p);
        d = __gcd(abs(x - y), n);
    }
}

// solution
void solve() {
    cnt.clear();
    ll a;
    cin >> a;
    PollardRho(a);
    ll k = 0;
    for (auto [p, c] : cnt) {
        k += c;
    }
    cout << k;
    for (auto [p, c] : cnt) {
        for (int i = 0; i < c; ++i) {
            cout << ' ' << p;
        }
    }
    cout << '\n';
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
