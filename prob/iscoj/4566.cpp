/* 
 * Created : 2023-12-29 09:37:51 lemonilemon
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
int m, k;

int mabs(ll a, int mod) {
    return (a % mod + mod) % mod;
}
int madd(int a, int b, int mod) {
    return mabs(a + b, mod);
}
int mmul(int a, int b, int mod) {
    return mabs(1ll * a * b, mod);
}
int fastpow(int a, int b, int mod) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(ret, a, mod);
        b >>= 1; 
        a = mmul(a, a, mod);
    }
    return ret;
}

// solution
void solve() {
    int A, B;
    string N;
    cin >> A >> B >> N >> m >> k;
    int b = (A - 2 * B) / 805, a = B - b;
    int ans = min(a, b);
    int n = 0;
    for(auto c : N) {
        n = mmul(n, 10, m - 1);
        n = madd(n, c - '0', m - 1);
    }    
    debug(n);
    cout << 1ll * ans * fastpow(k, n, m) << '\n';
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

