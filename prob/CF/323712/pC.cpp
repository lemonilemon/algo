/* 
 * Created : 2023-10-06 03:27:17 lemonilemon
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
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0) 
#define safe() ((void)0) 
#define expand(...) ((void)0)
#endif

// constants
const int MAXK = 10005, MAXN = 10005;
ll dp[MAXK];
int ord[MAXN];
int p[MAXN], c[MAXN], r[MAXN];

// solution
void solve() {
    int n, k, h; 
    cin >> n >> k >> h;
    for(int i = 0; i <= k; ++i) {
        dp[i] = h;
    }
    for(int i = 0; i < n; ++i) {
        ord[i] = i;
        cin >> p[i] >> c[i] >> r[i];
    }
    sort(ord, ord + n, [](int a, int b) {
        return c[a] < c[b];
    });
    for(int i = 0; i < n; ++i) {
        int cur = ord[i];
        for(int j = k; j >= p[cur]; --j) {
            if(dp[j - p[cur]] >= c[cur]) dp[j] = max(dp[j], dp[j - p[cur]] + r[cur] - c[cur]);
        }
    }
    cout << dp[k] << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

