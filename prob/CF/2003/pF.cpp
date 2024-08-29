/* 
 * Created : 2024-08-29 15:18:54 lemonilemon
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
const int MAXT = 300;
const int MAXN = 3005;
const int MAXM = 5;
const int INF = 1e9 + 7;
int dp[MAXN][1 << MAXM];
int a[MAXN], b[MAXN], c[MAXN];
int bmp[MAXN];
int bit[MAXN][1 << MAXM];
void modify(int val, int k, int idx) {
    for(; k < MAXN; k += k & -k) {
        bit[k][idx] = max(bit[k][idx], val);
    }
}
int query(int k, int idx) {
    int ret = -INF;
    for(; k > 0; k -= k & -k) {
        ret = max(ret, bit[k][idx]);
    }
    return ret;
}

int n, m;
int Try() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dis(0, m - 1);
    for(int i = 1; i <= n; ++i) {
        bmp[b[i]] = dis(rng);
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 1 << m; ++j) {
            dp[i][j] = -INF;
            bit[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    modify(dp[0][0], 1, 0);
    for(int i = 1; i <= n; ++i) {
        int newb = bmp[b[i]];
        for(int j = 0; j < 1 << m; ++j) {
            if(j >> newb & 1) {
                auto val = query(a[i], j ^ 1 << newb);
                dp[i][j] = val + c[i];
                modify(dp[i][j], a[i], j);
            }
        }
    }

    return query(n, (1 << m) - 1);
}
// solution
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i];
    for(int i = 1; i <= n; ++i) 
        cin >> b[i];
    for(int i = 1; i <= n; ++i) 
        cin >> c[i];
    int ans = -1;
    for(int t = 0; t < MAXT; ++t) {
        ans = max(Try(), ans);
    }
    cout << ans << '\n';
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

