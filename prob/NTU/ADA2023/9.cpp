/* 
 * Created : 2023-09-25 20:03:57 lemonilemon
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

const int MAXN = 1505, MAXM = 1505;
const ll INF = 1e18 + 7;
ll a[MAXN][MAXM];
ll dp[MAXN];
ll sufsum[MAXN][MAXM];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[n - i + 1][j];
            a[n - i + 1][j] *= -1;
        }
    }
    /*for(int i = 1; i <= n; ++i) {
        cerr << "> ";
        for(int j = 1; j <= m; ++j) {
            cerr << a[i][j] << ' ';
        }
        cerr << '\n';
    }*/
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i) {
        int x, y, d, r;
        cin >> x >> y >> d >> r;      
        int ul = x - d, lr = y - d;
        a[n - ul + 1][lr] += r;
    }
    /*for(int i = 1; i <= n; ++i) {
        cerr << "> ";
        for(int j = 1; j <= m; ++j) {
            cerr << a[i][j] << ' ';
        }
        cerr << '\n';
    }*/
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j > 0; --j) {
            sufsum[i][j] = sufsum[i - 1][j] + sufsum[i][j + 1] - sufsum[i - 1][j + 1] + a[i][j];
        }
    }
    /*cerr << ">>\n";
    for(int i = 1; i <= n; ++i) {
        cerr << "> ";
        for(int j = 1; j <= m; ++j) {
            cerr << sufsum[i][j] << ' ';
        }
        cerr << '\n';
    }*/
    for(int i = 1; i <= n; ++i) {
        dp[i] = -INF;
    }
    for(int j = 1; j <= m; ++j) {
        ll mx = 0;
        for(int i = 1; i <= n; ++i) {
            mx = max(dp[i] - sufsum[i][j], mx);
            dp[i] = max(sufsum[i][j] + mx, dp[i]);
            debug(i, j, dp[i]);
        }
    }
    ll mx = 0;
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, dp[i]);
    }
    cout << mx << '\n';
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

