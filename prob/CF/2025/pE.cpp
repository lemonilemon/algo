/* 
 * Created : 2024-10-14 23:54:10 lemonilemon
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
const int MOD = 998244353;
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
        if(b & 1) ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    } 
    return ret;
}
int inv(int a) {
    return fastpow(a, MOD - 2);
}
const int MAXM = 505, MAXN = 505;

int fact[MAXM << 1];
int h[MAXM];

int comb(int n, int m) {
    return mmul(fact[n], mmul(inv(fact[m]), inv(fact[n - m])));
}
int divi[MAXN][MAXM];

// solution
void solve() {
    int n, m;
    cin >> n >> m;
    h[0] = 1;
    for(int i = 1; i <= m; ++i) {
        h[i] = mmul(mmul(h[i - 1], 4 * i - 2), inv(i + 1));
    }
    fact[0] = 1;
    for(int i = 1; i <= m << 1; ++i) {
        fact[i] = mmul(fact[i - 1], i);
    }
    divi[0][0] = 1;
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j < i; ++j) {
            for(int k = i; k <= m; ++k) {
                divi[k][i] = madd(divi[k][i], mmul(comb(m, i - j), divi[k - 1][j]));
            }
        }
    }
    for(int k = (m >> 1) + (m & 1); k <= m; ++k) {
        int left = k - (m >> 1);
        int ans = 0;
        for(int i = 0; i <
        ans = madd(ans, mmul(divi[i][k], h[m >> 1]));
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

