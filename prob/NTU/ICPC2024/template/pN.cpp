/*
 * Created : 2024-11-15 02:24:01 lemonilemon
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
const int mod = 998244353;
const int inv2 = 499122177;
int mabs(ll a) { return (a % mod + mod) % mod; }
int madd(ll a, ll b) { return mabs(a + b); }
int mmul(ll a, ll b) { return mabs(1ll * a * b); }
void fwt(int *a, int n, int op) { // or
    for (int L = 2; L <= n; L <<= 1)
        for (int i = 0; i < n; i += L)
            for (int j = i; j < i + (L >> 1); ++j) {
                ll x = a[j], y = a[j + (L >> 1)];
                a[j] = mmul(madd(x, y), op);
                a[j + (L >> 1)] = mmul(madd(x, -y), op);
            }
}
// solution
const int MAXN = 20;
int a[1 << MAXN], b[1 << MAXN];
int c[1 << MAXN];
void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < (1 << N); ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << N); ++i) {
        cin >> b[i];
    }
    fwt(a, 1 << N, 1);
    fwt(b, 1 << N, 1);
    for (int i = 0; i < (1 << N); ++i) {
        c[i] = mmul(a[i], b[i]);
    }
    fwt(c, 1 << N, inv2);
    for (int i = 0; i < (1 << N); ++i) {
        cout << c[i] << " \n"[i == (1 << N) - 1];
    }
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
