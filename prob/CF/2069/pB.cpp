/*
 * Created : 2025-02-18 22:40:01 lemonilemon
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
const int MAXN = 705, MAXM = 705;
int a[MAXN][MAXM];
// solution
void solve() {
    int n, m;
    map<int, int> mp;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            mp[a[i][j]] = max(1, mp[a[i][j]]);
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (abs(dx) + abs(dy) != 1)
                        continue;
                    int ni = i + dx, nj = j + dy;
                    if (a[i][j] == a[ni][nj]) {
                        mp[a[i][j]] = 2;
                    }
                }
            }
        }
    }
    ll ans = 0;
    int mx = 0;
    for (auto [k, v] : mp) {
        // debug(k, v);
        ans += v;
        mx = max(mx, v);
    }
    ans -= mx;
    cout << ans << '\n';
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
