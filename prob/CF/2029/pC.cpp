/*
 * Created : 2024-11-09 22:48:04 lemonilemon
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
const int MAXN = 3e5 + 5;
const int INF = 1e9 + 7;
int dp[MAXN][3];
int a[MAXN];
int newrating(int x, int y) {
    if(x == y) return x;
    if(x > y) return x - 1;
    return x + 1;
}
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last0 = 0, last1 = -INF, last2 = -INF;
    for(int i = 1; i <= n; ++i) {
        int new0, new1, new2;
        new0 = newrating(last0, a[i]);
        new1 = max(last0, last1);
        new2 = max(newrating(last1, a[i]), newrating(last2, a[i]));
        last0 = new0;
        last1 = new1;
        last2 = new2;
    }
    cout << max(last1, last2) << '\n';

}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}