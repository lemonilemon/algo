/*
 * Created : 2025-10-19 02:11:31 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;
#define int ll

#define LOCAL

// debug template
#ifdef LOCAL
#define debug(args...) _debug(#args, args)
#define expand(arr, l, r) _expand(#arr, l, r, begin(arr) + l, begin(arr) + r)
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
const int MOD = 1e9 + 7;
const int MAXVAL = 1e7 + 5;
const int MAXC = 10005;
int premul[MAXC];
int fact[MAXVAL], invfact[MAXVAL];
bool isprime[MAXVAL];
vector<int> primes; // to 1e7
int mabs(ll a) { return (a % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmul(int a, int b) { return mabs(1ll * a * b); }

int fastpow(ll a, ll b) {
    a = mabs(a);
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int modinv(ll a) { return fastpow(a, MOD - 2); }
vector<pair<ll, int>> get_factors(ll n) {
    vector<pair<ll, int>> ret;
    for (auto p : primes) {
        if (1ll * p * p > n)
            break;
        if (n % p == 0) {
            ret.push_back({p, 1});
            n /= p;
            while (n % p == 0) {
                n /= p;
                ++ret.back().second;
            }
        }
    }
    if (n > 1)
        ret.push_back({n, 1});
    return ret;
}
int num2reach_x(const vector<pair<ll, int>> &factors) {
    int ret = 1;
    for (auto [p, c] : factors) {
        ret = mmul(ret, premul[c]);
        ret = mmul(ret, invfact[c]);
    }
    return ret;
}
// solution
void init() {
    for (int i = 2; i < MAXVAL; ++i) {
        isprime[i] = 1;
    }
    for (int i = 2; i < MAXVAL; ++i) {
        if (isprime[i])
            primes.push_back(i);
        for (auto p : primes) {
            if (1ll * i * p >= MAXVAL)
                break;
            isprime[i * p] = 0;
            if (i % p == 0)
                break;
        }
    }
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAXVAL; ++i) {
        fact[i] = mmul(fact[i - 1], i);
        invfact[i] = fastpow(fact[i], MOD - 2);
    }
}
void solve() {
    ll n;
    cin >> n;
    premul[1] = mabs(n);
    for (int i = 2; i < MAXC; ++i) {
        premul[i] = mmul(premul[i - 1], mabs(n - 1 + i));
    }
    ll A, B;
    cin >> A >> B;
    int ans = 0;
    for (ll i = 1; 1ll * i * i <= B; ++i) {
        if (!(B % i)) {
            if (i <= A) {
                ll x = i;
                int cnt1 = num2reach_x(get_factors(x));
                int cnt2 = num2reach_x(get_factors(B / x));
                int cnt = mmul(cnt1, cnt2);
                ans = madd(ans, cnt);
            }
            if (B / i != i) {
                ll x = B / i;
                if (x <= A) {
                    int cnt1 = num2reach_x(get_factors(x));
                    int cnt2 = num2reach_x(get_factors(B / x));
                    int cnt = mmul(cnt1, cnt2);
                    ans = madd(ans, cnt);
                }
            }
        }
    }
    cout << ans << '\n';
}

// main
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
