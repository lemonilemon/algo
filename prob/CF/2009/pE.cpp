/* 
 * Created : 2024-09-03 22:55:12 lemonilemon
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
void solve() {
    ll n, k; 
    cin >> n >> k;
    ll tot = 1ll * (2 * k + n - 1) * n / 2;
    int l = 1, r = n + 1;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        ll sum = 1ll * (2 * k + mid - 1) * mid / 2;
        if(2 * sum <= tot) l = mid;
        else r = mid;
    }
    ll sum1 = 1ll * (2 * k + l - 1) * l / 2;
    ll sum2 = 1ll * (2 * k + r - 1) * r / 2;
    cout << min(abs(tot - 2 * sum1), abs(tot - 2 * sum2)) << '\n';
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

