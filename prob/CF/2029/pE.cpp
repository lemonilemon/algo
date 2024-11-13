/*
 * Created : 2024-11-10 00:12:41 lemonilemon
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
const int MAXN = 4e5 + 5;
int a[MAXN];
vector<int> primes;
int mnp[MAXN];
bool isprime[MAXN];
void init() {
    for(int i = 2; i < MAXN; ++i) {
        isprime[i] = 1;
    }
    for(int i = 2; i < MAXN; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
            mnp[i] = i;
        }
        for(auto p : primes) {
            if(1ll * i * p >= MAXN) break;
            isprime[i * p] = 0;
            mnp[i * p] = p;
            if(i % p == 0) break;
        }
    }
}
// solution
void solve() {
    int n;
    cin >> n;
    int gcd = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        gcd = __gcd(gcd, a[i]);
    }
    if(gcd != 1) {
        cout << gcd << '\n';
        return;
    }
    vector<int> ps;
    for(int i = 1; i <= n; ++i) {
        if(isprime[a[i]]) ps.push_back(a[i]);
    }
    if(ps.size() >= 2) {
        cout << -1 << '\n';
        return;
    }
    if(ps.size() == 1) {
        if(ps[0] == 2) {
            cout << 2 << '\n';
            return;
        }
        for(int i = 1; i <= n; ++i) {
            if(a[i] % ps[0] == 0) continue;
            if(ps[0] <= mnp[a[i]]) continue;
            int target = mnp[a[i]];
            int can = target / 2;
            int mn = (ps[0] + can - 1) / can;
            // debug(a[i], ps[0], mn);
            if(a[i] / target < mn) {
                cout << "-1\n";
                return;
            }
        }
        cout << ps[0] << '\n';
        return;
    }
    cout << 2 << '\n';
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
