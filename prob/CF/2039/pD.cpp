/*
 * Created : 2024-11-24 00:08:10 lemonilemon
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
const int MAXM = 1e5 + 5;
const int MAXN = 1e5 + 5;
int s[MAXM];
int a[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }
    sort(s, s + m, [](int a, int b) { return a > b; });
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        vector<int> divs;
        for (int j = 1; 1ll * j * j <= i; ++j) {
            if (i % j != 0)
                continue;
            divs.push_back(j);
            divs.push_back(i / j);
        }
        sort(divs.begin(), divs.end());
        for (auto d : divs) {
            if (d == i)
                continue;
            if (s[cur] == a[d]) {
                ++cur;
                if (cur == m)
                    break;
            }
        }
        if (cur == m) {
            cout << "-1\n";
            return;
        }
        a[i] = s[cur];
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
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
