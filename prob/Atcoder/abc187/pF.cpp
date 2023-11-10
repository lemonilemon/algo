/* 
 * Created : 2023-11-10 03:07:51 lemonilemon
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
const int MAXN = 20;
bool graph[MAXN][MAXN];
int dp[1 << MAXN];
bool color[MAXN];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for(int i = 0; i < n; ++i) {
        graph[i][i] = 1;
    }
    dp[0] = 0;
    for(int i = 1; i < (1 << n); ++i) {
        int tempu = i;
        int u;
        bool flag = 1;
        while(tempu) {
            u = __lg(tempu);
            int tempv = i;
            int v;
            while(tempv) {
                v = __lg(tempv);
                flag &= graph[u][v];
                tempv ^= 1 << v;
            }
            tempu ^= 1 << u;
        }
        if(flag) dp[i] = 1;
        else dp[i] = n;
        for(int s1 = i; s1; s1 = (s1 - 1) & i) {
            int s2 = i ^ s1;
            dp[i] = min(dp[s1] + dp[s2], dp[i]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
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

