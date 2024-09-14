/* 
 * Created : 2024-09-03 23:11:53 lemonilemon
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
ll presum[MAXN << 1];
ll a[MAXN];
int n, q; 
ll calc(ll x) {
    if(x == 0) return 0;
    int c = (x + n - 1) / n;
    ll ret = 1ll * (c - 1) * presum[n];
    int r = (x - 1) % n + 1;
    // debug(x, c, r);
    ret += presum[c + r - 1] - presum[c - 1];
    return ret; 
}

// solution
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    for(int i = n + 1; i <= n << 1; ++i) {
        presum[i] = presum[i - 1] + a[i - n];
    }
    for(int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        // debug(calc(l - 1), calc(r));
        cout << calc(r) - calc(l - 1) << '\n';
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

