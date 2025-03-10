/* 
 * Created : 2024-08-15 23:23:31 lemonilemon
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
const int MAXA = 1e7 + 5;
int sg[MAXA];
int sg2[MAXA];
bool isprime[MAXA];
vector<int> primes;
void init() {
    for(int i = 2; i < MAXA; ++i) {
        isprime[i] = 1;
    }
    sg2[1] = 1;
    for(int i = 2; i < MAXA; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
            sg2[i] = i == 2? 0 : primes.size();
        }
        for(auto p : primes) {
            if(1ll * p * i >= MAXA) break;
            isprime[i * p] = 0;
            sg2[i * p] = sg2[p];
            if(i % p == 0) break;
        }
    }
    /*sg[0] = 0;
    for(int i = 1; i < MAXA; ++i) {
        set<int> s;
        for(int j = 1; j <= i; ++j) {
            if(__gcd(i, j) != 1) continue;
            s.insert(sg[i - j]);
        }
        for(int j = 0; j < MAXA; ++j) {
            if(!s.count(j)) {
                sg[i] = j;
                break;
            }
        }
    }
    for(int i = 0; i <= 100; ++i) {
        if(sg[i] != sg2[i]) debug(i, sg[i], sg2[i]);
    }*/
}
// solution
void solve() {
    int n; 
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        ans ^= sg2[a];
    }
    if(ans) cout << "Alice\n";
    else cout << "Bob\n";
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

