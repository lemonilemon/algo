/* 
 * Created : 2023-12-30 14:53:22 lemonilemon
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
const int MAXA = 1e6 + 5;
bool isprime[MAXA];
vector<int> primes;
void sieve() {
    for(int i = 2; i < MAXA; ++i) {
        isprime[i] = 1;
    }
    for(int i = 2; i < MAXA; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(1ll * i * p >= MAXA) break;
            isprime[i * p] = 0;
            if(i % p == 0) break;
        }
    }
}
// solution
void solve() {
    int a, b;
    cin >> a >> b;
    if(a == 1) {
        cout << b * b << '\n';
        return;
    }
    int ans = 1ll * a * b / __gcd(a, b);
    if(ans == b) cout << b * (b / a) << '\n';
    else cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

