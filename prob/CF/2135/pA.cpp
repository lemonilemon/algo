/*
 * Created : 2025-08-28 22:35:50 lemonilemon
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
int a[MAXN];
int dp[MAXN];
vector<int> cnt[MAXN];
int bit[MAXN];
void init(int n) {
    for (int i = 0; i <= n; ++i) {
        bit[i] = 0;
        cnt[i].clear();
    }
}
void modify(int x, int k) {
    for (; k < MAXN; k += k & -k)
        bit[k] = max(x, bit[k]);
}
int query(int k) {
    int res = 0;
    for (; k; k -= k & -k)
        res = max(res, bit[k]);
    return res;
}

// solution
void solve() {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
        dp[i] = 0;
        if (cnt[a[i]].size() >= a[i]) {
            auto &v = cnt[a[i]];
            int st = v[v.size() - a[i]];
            int mx = query(st - 1);
            dp[i] = mx + a[i];
        }
        modify(dp[i], i);
    }
    cout << query(n) << '\n';
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
