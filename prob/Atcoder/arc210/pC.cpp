/*
 * Created : 2025-11-16 20:24:34 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

// Docs for AC-library:
// https://atcoder.github.io/ac-library/production/document_en/
#include <atcoder/all>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace atcoder;
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

// using mint = modint;
// using mint = modint1000000007;
// using mint = modint998244353;
// constants
const int MAXN = 2e5 + 5;

bool check(vector<ll> &coin_cnt, int digit, ll need) {
    if (digit >= coin_cnt.size() + 10) {
        return false;
    }
    vector<pair<int, ll>> modifications;
    for (int i = digit; i >= 0; --i, need *= 10) {
        // debug(i, need, coin_cnt.size());
        if (need >= (ll)1e10) {
            break;
        }
        if (i >= coin_cnt.size())
            continue;
        if (coin_cnt[i] >= need) {
            coin_cnt[i] -= need;
            return true;
        }
        need -= coin_cnt[i];
        modifications.push_back({i, coin_cnt[i]});
        coin_cnt[i] = 0;
    }
    for (auto [idx, cnt] : modifications) {
        coin_cnt[idx] = cnt;
    }
    return false;
}

// solution
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    string ans;
    bool l0 = true;
    for (int i = n + 10; i >= 0; --i) {
        bool flag = false;
        for (int j = 9; j >= 1; --j) {
            if (check(coins, i, 1ll * j * m)) {
                ans += (char)('0' + j);
                l0 = false;
                flag = true;
                break;
            }
        }
        if (!flag && !l0) {
            ans += '0';
        }
    }
    if (ans.empty())
        ans = "0";
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
