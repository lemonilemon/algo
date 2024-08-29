/* 
 * Created : 2024-08-24 21:01:52 lemonilemon
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
const int MAXN = 1e6 + 5;
const int INF = 1e9 + 7;
int a[MAXN];
int dp1[MAXN][4];
int dp2[MAXN][8];


// solution
void solve() {
    int n, k; 
    cin >> n >> k;
    int cnt0 = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] == 0) ++cnt0;
    }

    if(cnt0 >= k) {
        cout << "0\n";
        return;
    }

    {
        for(int i = 0; i <= n; ++i) 
            for(int j = 0; j < 4; ++j) 
                dp1[i][j] = -INF;
        if(a[1] <= 1) dp1[1][1 << a[1]] = 1;
        else dp1[1][0] = 1;
               
        for(int i = 2; i <= n; ++i) {
            if(a[i] <= 1) {
                for(int j = 0; j < 4; ++j) {
                    if((j >> a[i]) & 1) {
                        dp1[i][j] = max(dp1[i - 1][j ^ (1 << a[i])], dp1[i - 1][j]);
                    }
                }
                for(int j = 0; j < 4; ++j) {
                    if(j == 1) continue;
                    dp1[i][1 << a[i]] = max(dp1[i][1 << a[i]], dp1[i - 1][j] + 1);
                }
            } else {
                for(int j = 0; j < 4; ++j) {
                    dp1[i][j] = dp1[i - 1][j];
                }
                for(int j = 0; j < 4; ++j) {
                    if(j == 1) continue;
                    dp1[i][0] = max(dp1[i][0], dp1[i - 1][j] + 1);              
                }
            }
            for(int j = 0; j < 4; ++j) {
                debug(i, j, dp1[i][j]);
            }
        }
        int mx = -INF;
        for(int j = 0; j < 4; ++j) {
            if(j == 1) continue;
            mx = max(mx, dp1[n][j]);
        }
        debug(mx);
        if(mx >= k) {
            cout << "1\n";
            return;
        }
    }

    {

        for(int i = 0; i <= n; ++i) 
            for(int j = 0; j < 8; ++j) 
                dp2[i][j] = INF;
        if(a[1] <= 2) dp2[1][1 << a[1]] = 1;
        else dp2[1][0] = 1;
        for(int i = 2; i <= n; ++i) {
            if(a[i] <= 2) {
                for(int j = 0; j < 8; ++j) {
                    if((j >> a[i]) & 1) {
                        dp2[i][j] = min(dp2[i - 1][j ^ (1 << a[i])], dp2[i - 1][j]);
                    }
                }
                for(int j = 0; j < 8; ++j) {
                    if(j == 3) continue;
                    dp2[i][1 << a[i]] = min(dp2[i][1 << a[i]], dp2[i - 1][j] + 1);
                }
            } else {
                for(int j = 0; j < 8; ++j) {
                    dp2[i][j] = dp2[i - 1][j];
                }
                for(int j = 0; j < 8; ++j) {
                    dp2[i][0] = min(dp2[i][0], dp2[i - 1][j] + 1);
                }
            }
            for(int j = 0; j < 8; ++j) {
                debug(i, j, dp2[i][j]);
            }

        }
        int mn = INF;
        for(int j = 0; j < 8; ++j) {
            if(j == 3) continue;
            mn = min(mn, dp2[n][j]);
        }
        debug(mn);
        if(mn <= k) {
            cout << "2\n";
            return;
        }
    }
    cout << "3\n";
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

