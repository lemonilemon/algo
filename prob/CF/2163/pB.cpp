/*
 * Created : 2025-11-10 23:11:24 lemonilemon
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
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> x(n);
    for (auto &i : p)
        cin >> i;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        x[i] = (c == '1');
    }
    int mnidx = 0;
    int mxidx = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] == n) {
            mxidx = i + 1;
        }
        if (p[i] == 1) {
            mnidx = i + 1;
        }
    }
    if (x[mnidx - 1] || x[mxidx - 1] || x[0] || x[n - 1]) {
        cout << "-1\n";
        return;
    }
    cout << 5 << '\n';
    cout << 1 << ' ' << mnidx << '\n';
    cout << 1 << ' ' << mxidx << '\n';
    cout << mnidx << ' ' << n << '\n';
    cout << mxidx << ' ' << n << '\n';
    cout << min(mnidx, mxidx) << ' ' << max(mnidx, mxidx) << '\n';
    return;
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
