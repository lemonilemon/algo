/*
 * Created : 2025-02-18 22:51:40 lemonilemon
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
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int n;
int mabs(ll a) { return (a % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmul(int a, int b) { return mabs(1ll * a * b); }

int bit[MAXN];
void modify(int k) {
    for (; k <= n; k += k & -k) {
        ++bit[k];
    }
}
int query(int k) {
    int res = 0;
    for (; k > 0; k -= k & -k) {
        res += bit[k];
    }
    return res;
}
int fastpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
int a[MAXN];
// solution
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        bit[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 2)
            modify(i);
    }
    int last = n + 1;
    vector<int> buf;
    int tot = 0;
    int cnt = 0;
    int minus = 0;
    int ans = 0;
    for (int l = n; l >= 1; --l) {
        if (a[l] == 1) {
            // tot = mmul(tot, fastpow(2, query(last - 1) - query(l - 1)));
            // while (!buf.empty()) {
            //     tot =
            //         madd(fastpow(2, query(buf.back() - 1) - query(l - 1)),
            //         tot);
            //     buf.pop_back();
            // }
            ans = madd(ans, tot - cnt);
            last = l;
        } else if (a[l] == 3) {
            ++cnt;
            ++tot;
            buf.push_back(l);
        } else {
            tot <<= 1;
            tot %= MOD;
        }
    }
    cout << ans << '\n';
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
