/*
 * Created : 2025-11-10 23:29:03 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;

// #define LOCAL

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
const int INF = 1e9 + 7;
vector<int> bit[3];
void clear(int t, int n) { bit[t] = vector<int>(n + 1, 0); }

void modify(int t, int x, int v) {
    debug(t, x, v);
    for (; x < bit[t].size(); x += x & -x) {
        bit[t][x] = max(bit[t][x], v);
    }
}

int binary_search(int t, int x) {

    int ret = 0;
    for (int k = __lg(bit[t].size()); k >= 0; --k) {
        int idx = ret + (1 << k);
        if (idx >= bit[t].size())
            continue;
        debug(idx, bit[t][idx], x);
        if (bit[t][idx] <= x) {
            ret = idx;
        }
    }
    ++ret;
    debug(t, x, ret);
    return ret;
}

// solution
void solve() {
    int n;
    cin >> n;
    vector<int> a[3];
    vector<vector<int>> val2idx[3];
    for (int i = 1; i <= 2; ++i) {
        clear(1, n);
        clear(2, n);
        a[i] = vector<int>(n + 1);
        val2idx[i] = vector<vector<int>>(2 * n + 1, vector<int>());
    }
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
        if (i == 2)
            reverse(a[i].begin() + 1, a[i].end());
        for (int j = 1; j <= n; ++j) {
            modify(i, j, a[i][j]);
            val2idx[i][a[i][j]].push_back(j);
        }
    }
    ll ans = 0;
    for (int l = 1, r = 1; l <= 2 * n; ++l) {
        for (int i = 1; i <= 2; ++i) {
            int last = l - 1;
            for (auto idx : val2idx[i][last]) {
                modify(i, idx, INF);
            }
        }
        while (r <= 2 * n) {
            int up = binary_search(1, r) - 1;
            int down = binary_search(2, r) - 1;
            debug(l, r, up, down);
            if (up + down > n)
                break;
            ++r;
        }
        debug(l, r);
        ans += 2 * n - r + 1;
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
