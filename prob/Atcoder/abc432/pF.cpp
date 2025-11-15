/*
 * Created : 2025-11-15 21:05:32 lemonilemon
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
const int MAXN = 20;
int a[MAXN];
ll sum[1 << MAXN];
int dp[1 << MAXN];
int dif_index[1 << MAXN];
vector<int> backtrack[1 << MAXN];

// solution
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (1 << i)) {
                sum[mask] += a[i];
            }
        }
    }
    if (sum[(1 << n) - 1] % n != 0) {
        cout << -1 << '\n';
        return;
    }
    int target = sum[(1 << n) - 1] / n;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = __builtin_popcount(i);
        dp[i] = 1e9;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                int prev = i ^ (1 << j);
                int current_dif = sum[i] - target * cnt;
                int prev_dif = sum[prev] - target * (cnt - 1);
                if (prev_dif != 0 && current_dif != prev_dif) {
                    if (dp[prev] + 1 < dp[i]) {
                        dp[i] = dp[prev] + 1;
                        backtrack[i] = {dif_index[prev], j, prev_dif};
                        dif_index[i] = j;
                    }
                } else {
                    if (dp[prev] < dp[i]) {
                        dp[i] = dp[prev];
                        backtrack[i] = {dif_index[prev], j, 0};
                        if (prev_dif == 0) {
                            dif_index[i] = j;
                        } else {
                            dif_index[i] = dif_index[prev];
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> ans;
    int cur = (1 << n) - 1;
    while (cur != 0) {
        if (backtrack[cur][2] != 0)
            ans.push_back(backtrack[cur]);
        cur ^= (1 << backtrack[cur][1]);
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
