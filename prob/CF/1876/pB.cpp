/* 
 * Created : 2023-10-20 08:01:56 lemonilemon
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
const int MAXN = 1e5 + 5, MOD = 998244353;
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
int fastpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(a, ret);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int rev(int a) {
    return fastpow(a, MOD - 2);
}
int a[MAXN];
int dp[MAXN], indeg[MAXN];
vector<int> graph[MAXN];

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 2; 1ll * i * j <= n; ++j) {
            graph[i * j].push_back(i);
            ++indeg[i];
        }
    }
    for(int i = 1; i <= n; ++i) {
        dp[i] = a[i];
    }
    queue<int> que;
    for(int i = 1; i <= n; ++i) {
        if(!indeg[i]) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(auto v : graph[u]) {
            dp[v] = max(dp[v], dp[u]);
            if(!(--indeg[v])) que.push(v);
        }
    }
    map<int, int> mp;
    for(int i = 1; i <= n; ++i) {
        if(mp.count(dp[i])) ++mp[dp[i]];
        else mp[dp[i]] = 1;
    }
    int curcnt = 0;
    int ans = 0;
    for(auto [v, cnt] : mp) {
        ans = madd(ans, mmul(v, mmul(fastpow(2, curcnt), fastpow(2, cnt) - 1)));
        curcnt += cnt;
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

