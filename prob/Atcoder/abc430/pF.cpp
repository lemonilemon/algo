/*
 * Created : 2025-11-03 20:43:03 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;

// #define LOCAL

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
const int MAXN = 3e5 + 5;
int lcnt[MAXN], rcnt[MAXN];
int dif[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        lcnt[i] = rcnt[i] = dif[i] = 0;
    }
    int current_lrun = 0, current_rrun = 0;
    for (int i = 1; i < n; ++i) {
        char c = s[i - 1];
        if (c == 'L') {
            ++current_lrun;
            current_rrun = 0;
        } else {
            ++current_rrun;
            current_lrun = 0;
        }
        lcnt[i + 1] += current_rrun;
        rcnt[i + 1] += current_lrun;
    }
    current_lrun = 0, current_rrun = 0;
    for (int i = n - 1; i >= 1; --i) {
        char c = s[i - 1];
        if (c == 'L') {
            ++current_lrun;
            current_rrun = 0;
        } else {
            ++current_rrun;
            current_lrun = 0;
        }
        lcnt[i] += current_lrun;
        rcnt[i] += current_rrun;
    }
    for (int i = 1; i <= n; ++i) {
        debug(i, lcnt[i], rcnt[i]);
        int l = lcnt[i] + 1, r = n - rcnt[i];
        ++dif[l];
        --dif[r + 1];
    }
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        c += dif[i];
        cout << c << " \n"[i == n];
    }
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
