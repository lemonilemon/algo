/* 
 * Created : 2024-08-30 01:33:38 lemonilemon
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
const int MAXX = 1e6 + 5;
int mnp[MAXX], pmnp[MAXN];
bool isprime[MAXX];
int cnt[MAXX];
vector<int> primes;

void init() {
    for(int i = 2; i < MAXX; ++i) {
        isprime[i] = 1;
    }
    for(int i = 2; i < MAXX; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
            mnp[i] = i;
            pmnp[i] = i;
        } 
        for(auto p : primes) {
            if(1ll * i * p >= MAXX) break;
            isprime[i * p] = 0;
            mnp[i * p] = p;
            if(mnp[i] == p) pmnp[i * p] = p * pmnp[i];
            else pmnp[i * p] = p;
            if(i % p == 0) break;
        }
    }
}
// solution
void solve() {
    int n; 
    cin >> n;
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

