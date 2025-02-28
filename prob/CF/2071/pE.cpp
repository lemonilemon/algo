/*
 * Created : 2025-03-01 00:14:34 lemonilemon
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
const int MOD = 998244353;
const int MAXN = 1e5 + 5;
int mabs(ll x) { return (x % MOD + MOD) % MOD; }
int madd(int x, int y) { return (x + y) % MOD; }
int mmul(int x, int y) { return (1LL * x * y) % MOD; }
int mpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int minv(int x) { return mpow(x, MOD - 2); }
pair<int, int> mul(pair<int, int> a, pair<int, int> b) {
    return {mmul(a.first, b.first),
            madd(mmul(a.first, b.second), mmul(a.second, b.first))};
}
pair<int, int> inv(pair<int, int> a) {
    auto &[a0, a1] = a;
    int temp = minv(a0);
    return {temp, mmul(mmul(temp, temp), -a1)};
}
pair<int, int> div(pair<int, int> a, pair<int, int> b) {
    auto c = inv(b);
    return mul(a, c);
}
int fall[MAXN];
pair<int, int> f[MAXN];
pair<int, int> a[MAXN];
int par[MAXN];
pair<int, int> all_a;
vector<int> graph[MAXN];
void dfs(int u, int pa = -1) {
    par[u] = pa;
    pair<int, int> sur_a = {1, 0};
    pair<int, int> new_a = {1, 0};
    for (int v : graph[u]) {
        sur_a = mul(sur_a, f[v]);
        new_a = mul(new_a, f[v]);
    }
    for (int v : graph[u]) {
        auto c = div(sur_a, f[v]);
        a[v] = div(a[v], c);
    }
}
// solution
void solve() {
    int n;
    cin >> n;
    all_a = {1, 0};
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
        a[i] = {1, 0};
    }
    for (int i = 1; i <= n; ++i) {
        int p, q;
        cin >> p >> q;
        fall[i] = mmul(p, minv(q));
        f[i] = {fall[i], mabs(1 - fall[i])};
        all_a = mul(all_a, f[i]);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = div(all_a, f[i]);
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
