/* 
 * Created : 2024-07-29 23:01:25 lemonilemon
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
const int MAXN = 16;
const int INF = 1e9;
char c[MAXN];
int r[MAXN], b[MAXN];
int dp[1 << MAXN][128];

// solution
void solve() {
    int n;
    cin >> n;
    ll rsum = 0, bsum = 0; 
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        cin >> r[i] >> b[i];
        rsum += r[i];
        bsum += b[i];
    }
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < 128; ++j) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < (1 << n); ++i) {
        int rcnt = 0, bcnt = 0;
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1) {
                if(c[j] == 'R') ++rcnt;
                else ++bcnt;
            }
        }
        int rsave = 0, bsave = 0;
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1) continue;
            if(r[j] - rcnt > 0) ++rsave;
            if(b[j] - bcnt > 0) ++bsave;
        }
        for(int j = 0; j < 128; ++j) {
            for(int k = 0; k < n; ++k) {
                if((i >> k) & 1) continue;
                int k_rsave = rsave, k_bsave = bsave;
                if(r[k] - rcnt > 0) --k_rsave;
                if(b[k] - bcnt > 0) --k_bsave;
                int nxt = i | (1 << k);
                if(c[k] == 'R') {
                    if(j + k_rsave >= 128) continue;
                    dp[nxt][j + k_rsave] = max(dp[nxt][j + k_rsave], dp[i][j]); 
                } else dp[nxt][j] = max(dp[nxt][j], dp[i][j] + k_bsave);
            }
        }
    }
    /*for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < 4; ++j) {
            cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
        } 
    }*/
    int mncost = INF;
    for(int i = 0; i < 128; ++i) {
        int cost = max(rsum - i, bsum - dp[(1 << n) - 1][i]);
        mncost = min(mncost, cost);
    }
    cout << mncost + n << '\n';
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

