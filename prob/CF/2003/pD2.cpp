/* 
 * Created : 2024-08-28 11:28:04 lemonilemon
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



// solution
const int MAXN = 2e5 + 5;
int cnt[MAXN];
vector<int> to[MAXN];
bool vis[MAXN][2];
int dp[MAXN][2]; // 0: need to choose 1: not choose yet
int dfs(int u, bool c) {
    if(vis[u][c]) return dp[u][c];
    vis[u][c] = 1;
    if(c == 0) {
        if(to[u].size() == 0) return dp[u][c] = 0;
        if(to[u].size() == 1) return dp[u][c] = u;
        dp[u][c] = 0;
        for(auto v : to[u]) {
            dp[u][c] = max(dp[u][c], dfs(v, 1));
        }
        return dp[u][c];
    }
    if(to[u].size() == 0) return dp[u][c] = u;
    dp[u][c] = 0;
    for(auto v : to[u]) {
        dp[u][c] = max(dfs(v, 1), dp[u][c]);
    }
    return dp[u][c];
}
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    int tomx = 0;
    vector<pair<int, int> > temp;
    for(int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for(int j = 0; j <= l + 1; ++j) {
            cnt[j] = 0;
        }
        for(int j = 0; j < l; ++j) {
            int a;
            cin >> a;
            if(a <= l + 1) ++cnt[a];
        }
        int cur = 0;
        while(cnt[cur] > 0) ++cur;
        int mex = cur;
        ++cur;
        while(cnt[cur] > 0) ++cur;
        // debug(mex, cur);
        temp.push_back({mex, cur});
        tomx = max(tomx, cur);
    }
    for(int i = 0; i <= tomx; ++i) {
        to[i].clear();
    }
    for(auto [mex, cur] : temp) {
        to[mex].push_back(cur);
    }
    int mx0 = 0;
    for(int i = 0; i <= tomx; ++i) {
        vis[i][0] = vis[i][1] = 0;
    }
    for(int i = 0; i <= tomx; ++i) {
        if(!vis[i][0]) 
            mx0 = max(mx0, dfs(i, 0));
    }
    for(int i = 0; i <= tomx; ++i) {
        if(!vis[i][1])
            dfs(i, 1); 
    }
    ll ans = 0;
    for(int i = 0; i <= min(m, tomx); ++i) {
        ans += max(dp[i][1], mx0);
    }
    if(m > tomx)
        ans += 1ll * (m - tomx) * (m + tomx + 1) / 2;
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

