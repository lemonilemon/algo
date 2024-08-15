/* 
 * Created : 2024-08-15 22:06:28 lemonilemon
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
const int MAXP = 6e6 + 5;
const int MAXN = 4e5 + 5;
bool isprime[MAXP];
bool ans[MAXN];
vector<int> primes;

void sieve() {
    for(int i = 2; i < MAXP; ++i) isprime[i] = 1;
    for(int i = 2; i < MAXP; ++i) {
        if(isprime[i]) primes.push_back(i);
        for(auto p: primes) {
            if(1ll * p * i >= MAXP) break;
            isprime[i * p] = 0;
            if(i % p == 0) break;
        }

    }
}

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        ans[i] = 0;
    }
    ll dif = 0;
    for(int i = 0; i < n; ++i) {
        dif += primes[i];
    }
    int k = n - 1;
    while(dif - primes[k] * 2 >= 0) {
        ans[k] = 1;
        dif -= primes[k] * 2;
        --k;
    }
    while(dif >= 4) {
        auto p = upper_bound(primes.begin(), primes.end(), dif / 2);
        int val = *prev(p);
        debug(p - primes.begin() - 1);
        ans[p - primes.begin() - 1] = 1;
        dif -= val * 2;
    }
    if(dif > 2) {
        ans[0] = 1;
        dif = 4 - dif;
    }
    for(int i = 0; i < n; ++i) {
        cout << (char)('A' + ans[i]);
    }
    cout << '\n';
    debug(dif);
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

