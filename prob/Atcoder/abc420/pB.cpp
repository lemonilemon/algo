/*
 * Created : 2025-08-24 20:01:51 lemonilemon
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
const int MAXN = 100;
const int MAXM = 105;
string s[MAXN];
int score[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        if (cnt0 == 0 || cnt1 == 0) {
            for (int j = 0; j < n; ++j) {
                ++score[j];
            }
        } else if (cnt0 < cnt1) {
            for (int j = 0; j < n; ++j) {
                if (s[j][i] == '0') {
                    ++score[j];
                }
            }
        } else {
            for (int j = 0; j < n; ++j) {
                if (s[j][i] == '1') {
                    ++score[j];
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, score[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (score[i] == mx) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
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
