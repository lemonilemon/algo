/* 
 * Created : 2024-03-22 22:46:08 lemonilemon
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
ll a[MAXN];
ll presum[MAXN];
int fastpow(int a, ll b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(ret, a);
        a = mmul(a, a); 
        b >>= 1;
    }
    return ret;
}


// solution
void solve() {
    int n, k;
    cin >> n >> k;
    ll mnpre = 0;
    ll mxdiff = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
        mxdiff = max(mxdiff, presum[i] - mnpre);
        mnpre = min(mnpre, presum[i]);
    }
    mxdiff = mabs(mxdiff);
    int increase = mmul(fastpow(2, k) - 1, mxdiff);
    cout << madd(mabs(presum[n]), increase) << '\n';
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

