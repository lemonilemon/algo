/*
 * Created : 2025-08-28 23:55:28 lemonilemon
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

const int MAXN = 1e5;

// solution
void solve() {
    cout << "? " << MAXN;
    for (int i = 0; i < MAXN; ++i) {
        cout << " 1";
    }
    cout << endl;
    int cnt;
    cin >> cnt;
    if (cnt == 1) {
        cout << "! " << MAXN << endl;
        return;
    }
    int least = (MAXN + cnt - 1) / cnt;
    cout << "? " << least * 2;
    for (int i = 0; i < least; ++i) {
        int val = (i >> 1) + 1;
        if (i & 1) {
            cout << ' ' << least - val + 1 << ' ' << least;
        } else {
            cout << ' ' << val << ' ' << least;
        }
    }
    cout << endl;
    cin >> cnt;
    cout << "! " << least * 3 - cnt << endl;
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
