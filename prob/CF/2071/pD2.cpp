/*
 * Created : 2025-02-28 23:15:59 lemonilemon
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
bool a[MAXN << 1];
bool prexor[MAXN << 1];
ll presum[MAXN << 1];
ll n, l, r;
bool getval(ll m) {
    // debug(m);
    if (m <= n)
        return a[m];
    ll idx = m >> 1;
    if (idx <= (n << 1))
        return prexor[idx];
    if (n & 1) {
        if (idx & 1)
            return prexor[n];
        else
            return prexor[n] ^ getval(idx);
    } else {
        if (idx & 1)
            return prexor[n + 1];
        else
            return prexor[n + 1] ^ getval(idx);
    }
}

ll getpresum(ll m, bool rev = 0) {
    if (m <= 2 * n)
        return presum[m];
    if (n & 1) {

    } else {
    }
}
// solution
void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prexor[i] = prexor[i - 1] ^ a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        a[i] = prexor[i >> 1];
        prexor[i] = prexor[i - 1] ^ a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    cout << getval(l) << '\n';
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
