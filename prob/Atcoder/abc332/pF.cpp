/* 
 * Created : 2023-12-10 13:10:54 lemonilemon
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
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int msub(int a, int b) {
    return mabs(a - b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
int a[MAXN];
struct Node {
    int le, ex;
    int letag, extag;
    Node(): le(1), ex(0), letag(0), extag(0) {}
}
vector<tuple<int, int, int> > query;

int fastpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(a, ret);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int inv(int x) {
    return fastpow(x, MOD - 2);
}
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i <= n; ++i) {
        le[i] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        modify1(i, 1);
    }
    for(int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        query.push_back(make_tuple(l, r, x));
    }
    reverse(query.begin(), query.end());
    for(auto [l, r, x] : query) {
        int pos = inv(r - l + 1);
        int exval = mmul(pos, x);
        modify1(l, -pos);
        modify1(r + 1, pos);
        modify2(l, exval);
        modify2(r + 1, -exval);
    }
    for(int i = 1; i <= n; ++i) {
        int left = msub(query1(i), query1(i - 1));
        int exval = msub(query2(i), query2(i - 1));
        exval = madd(mmul(left, a[i]), exval);
        cout << 
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

