/* 
 * Created : 2024-09-30 01:19:17 lemonilemon
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
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
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
int inv(int x) {
    return fastpow(x, MOD - 2);
}
const int inv10000 = inv(10000);
int a[MAXN], p[MAXN];
int pos[2][1 << 10];

// solution
void solve() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < (1 << 10); ++j) {
            pos[i][j] = 0;
        }
    }
    pos[1][0] = 1;
    for(int i = 0; i < n; ++i) {
        int pp = mmul(p[i], inv10000), np = mabs(1 - pp);
        for(int j = 0; j < (1 << 10); ++j) {
            pos[i & 1][j] = madd(mmul(pos[!(i & 1)][j ^ a[i]], pp), mmul(pos[!(i & 1)][j], np));
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << 10); ++i) {
        ans = madd(ans, mmul(pos[(n - 1) & 1][i], mmul(i, i)));
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

