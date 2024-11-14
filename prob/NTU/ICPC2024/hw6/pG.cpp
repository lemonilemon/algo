/*
 * Created : 2024-11-11 11:37:26 lemonilemon
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
const int MAXN = 1e5 + 5;
const int MAXA = 1e6 + 5;
vector<int> primes;
bool isprime[MAXA];
ll a[MAXN];
void init() {
    for(int i = 2; i < MAXA; ++i)
        isprime[i] = 1;
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
const int B = 55;
const int MAXLOGM = 50;
const ll INF = 1e18 + 7;
ll S, M;
vector<ll> factors;
unordered_map<ll, int> have;
unordered_map<ll, int> factor2idx;
vector<pair<ll, int> > ps;
void get_factors(int curp = 0, ll Mleft = M, ll curM = 1) {
    if(curp == ps.size()) return;
    auto [p, cnt] = ps[curp];
    for(int i = 0; i <= cnt; ++i) {
        get_factors(curp + 1, Mleft, curM);
        if(i > 0) factors.push_back(curM);
        curM *= p;
        Mleft /= p;
    }
}
map<pair<ll, ll>, ll> dp[B]; // dp[max factor][curM(also a factor)][{curS, curM}] = min cost
int cnt1 = 0;
ll dfs(ll cur, ll curS, ll curM, ll curcost) {
    if(cur + curS > S || cur * curM > M) return curcost + abs(cnt1 - (S - curS));
    if((M / curM) % cur != 0) return dfs(cur + 1, curS, curM, curcost);
    ll mn = INF;
    int mxcnt = 0;
    while(cur + curS > S || cur * curM > M) {
        ++mxcnt;
        curS += cur;
        curM *= cur;
        if(curS <= S && curM <= M) {
            mn = min(dfs(cur + 1, curS, curM, curcost + 1), mn);
        }
    }
    for(int i = 0; i <= mxcnt; ++i) {
        curS -= cur;
        curM /= cur;
    }
    return mn;
}
// solution
void solve() {
    int n;
    cin >> n >> S >> M;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] == 1) ++cnt1;
        if(M % a[i] == 0) {
            ++have[a[i]];
        } else ++ans;
    }
    {
        ll tmp = M;
        for(auto p : primes) {
            int cnt = 0;
            while(tmp % p == 0) {
                tmp /= p;
                ++cnt;
            }
            if(cnt) ps.push_back({p, cnt});
        }
        if(tmp > 1) ps.push_back({tmp, 1});
        get_factors();
        factors.push_back(1);
        sort(factors.begin(), factors.end());
        for(int i = 0; i < factors.size(); ++i) {
            factor2idx[factors[i]] = i;
        }
    }
    dp[0][{0, 1}] = n - cnt1;
    for(int i = 1; i < B; ++i) {
        for(auto [lastS, lastM] : dp[i - 1]) {

        }
    }
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
