/* 
 * Created : 2023-08-05 17:29:45 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = __int128;


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
#endif

// constants
ll INF = 1e18;


// solution
pair<ll, ll> exgcd(ll x, ll y) {
    if(y > x) {
        auto ret = exgcd(y, x);
        swap(ret.first, ret.second);
        return ret;
    }
    if(!y) return make_pair(1, 0);
    auto ret = exgcd(y, x % y); 
    return make_pair(ret.second, ret.first - (x / y) * ret.second);
}
ll mabs(ll a, ll mod) {
    return (a % mod + mod) % mod;
}
void solve() {
    long long int n[3]; 
    long long int mn = INF, mx = 0;
    for(int i = 0; i < 3; ++i) {
        cin >> n[i];
        mn = min(mn, n[i]);
        mx = max(mx, n[i]);
    }
    debug(mn, mx);
    ll ans = 0;
    ll mul = n[0] * n[1] * n[2];
    for(int i = 0; i < 3; ++i) {
        long long int p;
        cin >> p;
        ll a = exgcd(mul / n[i], n[i]).first;
        a = mabs(a, n[i]);
        ans += (mul / n[i]) * a * p;
    }
    for(long long int i = 0; i <= mn; ++i) {
        if((i * i * i - ans) % mul == 0) {
            cout << i << '\n';
            return;
        }
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

