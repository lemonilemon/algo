/* 
 * Created : 2024-08-28 13:28:26 lemonilemon
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
const int MAXN = 5005, INF = 1e9;
int dp[MAXN][MAXN]; 
int must[MAXN];
int le[MAXN];
// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) {
        must[i] = -1;
        le[i] = 0;
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = -INF;
        }
    }
    if(m == 0) {
        cout << n * (n - 1) / 2 << '\n';
        return;
    }
    vector<pair<int, int> > seg;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end());
    int mnl = seg[0].first, mnr = seg[0].second, mxl = seg[0].first, mxr = seg[0].second;
    for(int i = 1; i <= m; ++i) {
        if(i == m || seg[i].first > mxr) {
            if(mxl >= mnr) {
                cout << "-1\n";
                return;
            }
            for(int j = mnl; j < mxl; ++j) {
                must[j] = 0;
            }
            for(int j = mnr + 1; j <= mxr; ++j) {
                must[j] = 1;
            }
            le[mnr] = mxl;
            // debug(mnr, le[mnr]);
            if(i != m) {
                auto [l, r] = seg[i];
                mnl = mxl = l; 
                mnr = mxr = r;
            }
        } else {
            auto [l, r] = seg[i];
            mnl = min(mnl, l);
            mxl = max(mxl, l);
            mnr = min(mnr, r);
            mxr = max(mxr, r);
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        if(le[i]) {
            for(int j = 0; j <= i; ++j) {
                for(int k = le[i]; k < i; ++k) {
                    int cnt0 = k - le[i] + 1;
                    int cnt1 = i - k;
                    if(j - cnt1 >= 0) dp[i][j] = max(dp[i][j], dp[le[i] - 1][j - cnt1] + cnt0 * (j - cnt1));
                }
            }
        } else {
            for(int j = 0; j <= i; ++j) {
                dp[i][j] = -INF;
                if(must[i] != 1) dp[i][j] = max(dp[i - 1][j] + j, dp[i][j]);
                if(must[i] != 0 && j > 0) dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
            }
        }
        /*for(int j = 0; j <= i; ++j) {
            debug(i, j, dp[i][j]);
        }*/
    }
    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        int val = dp[n][i] + i * (i - 1) / 2 + (n - i - 1) * (n - i) / 2;
        // debug(val);
        ans = max(ans, dp[n][i] + i * (i - 1) / 2 + (n - i - 1) * (n - i) / 2);
    }
    cout << ans << '\n';
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

