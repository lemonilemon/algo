/*
 * Created : 2025-11-15 22:48:18 lemonilemon
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
using mint = modint998244353;
// constants
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;
const int MAXA = 5e5 + 5;
const int MAXB = 5e5 + 5;
mint fact[MAXM + 1], invfact[MAXM + 1];
// solution
void solve() {
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i <= MAXM; ++i) {
        fact[i] = fact[i - 1] * i;
        invfact[i] = fact[i].inv();
    }

    int n, m;
    cin >> n >> m;
    vector<int> ca(MAXA, 0), cb(MAXB, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++ca[a];
    }
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        ++cb[b];
    }
    vector<int> f;
    vector<int> g;
    for (int i = 0; i < MAXM; ++i) {
        f.push_back((cb[i] * invfact[i]).val());
        g.push_back(invfact[i].val());
    }
    auto h = convolution(f, g);
    mint ans = 0;
    for (int i = 0; i <= MAXM; ++i) {
        ans += fact[i] * ca[i] * h[i];
    }
    cout << ans.val() << '\n';
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
