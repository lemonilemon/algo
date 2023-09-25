/* 
 * Created : 2023-09-22 13:42:39 lemonilemon
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
const int MAXN = 1e5 + 5;
const int MAXK = 32;
const int MAXM = 10;
ll a[MAXN], c[MAXK];
ll dp[MAXN][MAXK];
ll presum[MAXM][MAXN];

// solution
ll n, m, k;
ll query(ll l, ll r, ll curl = 0, ll curr = 1ll * n * (1 << k) - 1, int curval = 0, int depth = 0) {
    // debug(l, r, curl, curr, curval);
    if(l == curl && r == curr) return dp[curval][depth]; 
    if(depth == k) return presum[curval][r - curl + 1] - presum[curval][l - curl]; 
    ll curmid = (curl + curr) >> 1; 
    if(r <= curmid) return query(l, r, curl, curmid, curval, depth + 1);
    if(l > curmid) return query(l, r, curmid + 1, curr, (curval + c[depth]) % m, depth + 1);
    return query(l, curmid, curl, curmid, curval, depth + 1) + query(curmid + 1, r, curmid + 1, curr, (curval + c[depth]) % m, depth + 1);
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        presum[i][0] = 0;
        for(int j = 1; j <= n; ++j) {
            presum[i][j] += presum[i][j - 1] + (i + a[j]) % m;
            // debug(i, j, presum[i][j]);
        }
    }
    for(int i = 0; i < k; ++i) {
        cin >> c[i]; 
    }
    for(int i = 0; i < m; ++i) {
        dp[i][k] = presum[i][n];
    }
    for(int d = k - 1; d >= 0; --d) {
        for(int i = 0; i < m; ++i) {
            dp[i][d] = dp[i][d + 1] + dp[(i + c[d]) % m][d + 1];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
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

