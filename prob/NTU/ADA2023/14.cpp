/* 
 * Created : 2023-10-17 04:19:44 lemonilemon
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
const int MAXN = 5e5 + 5, INF = 1e9 + 7;
int c[MAXN];
int s[MAXN];
int dp[MAXN];
int ord[MAXN];
// solution
void solve() {
    int n, g;
    cin >> n >> g;
    for(int i = 1; i <= n; ++i) {
        ord[i] = i;
        dp[i] = INF;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    sort(ord + 1, ord + n + 1, [](int a, int b) {
        return s[a] < s[b];
    });
    for(int i = 1; i <= n; ++i) {
        debug(s[ord[i]]);
    }
    int mxc = 0, cnt = 1;
    int r = 0;
    while(r < n) {
        int nxt = ord[r + 1];
        if(s[nxt] == 0) {
            mxc = max(mxc, c[nxt]); 
            if(c[nxt] >= s[g]) dp[nxt] = cnt;
            ++r;
        } else break;
    }
    while(true) {
        ++cnt;
        int curmxc = mxc;
        bool flag = 0;
        while(r < n) {
            int nxt = ord[r + 1];
            debug(nxt, s[nxt], curmxc);
            if(s[nxt] <= curmxc) {
                mxc = max(c[nxt], mxc);
                if(c[nxt] >= s[g]) dp[nxt] = cnt;
                ++r;
                flag = 1;
            } else break;
        }
        if(!flag) break;
    }
    dp[g] = 0; 
    for(int i = 1; i <= n; ++i) {
        if(dp[i] == INF) cout << "-1";
        else cout << dp[i];
        cout << " \n"[i == n];
    }
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

