/*
 * Created : 2025-11-30 00:07:59 lemonilemon
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
const int MAXP = 1e6 + 5;
bool isprime[MAXP];
vector<int> primes;
void init() {
    for (int i = 2; i < MAXP; ++i)
        isprime[i] = true;
    for (int i = 2; i < MAXP; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (1ll * i * p >= MAXP)
                break;
            isprime[i * p] = false;
            if (i % p == 0)
                break;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    ll val = 1;
    for (int i = 0; i < 30; ++i) {
        val <<= 1;
    }
    for (int i = 0; i < 20; ++i) {
        val *= 3;
    }
    debug(val);
    for (int i = 0; i < n; ++i) {
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
