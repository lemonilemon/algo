/*
 * Created : 2025-08-24 20:44:53 lemonilemon
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
const int MAXM = 2e5 + 5;
vector<vector<int>> mat;
vector<int> h[MAXM];
int cur_h_idx[MAXM];
int mnh[MAXM];

// solution
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    mat.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            mat[i][j] = c == '#';
            if (mat[i][j])
                h[j].push_back(i);
        }
    }
    for (int j = 1; j <= m; ++j) {
        h[j].push_back(n + 1);
        cur_h_idx[j] = 0;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            while (h[j][cur_h_idx[j]] < i)
                ++cur_h_idx[j];
            mnh[j] = h[j][cur_h_idx[j]];
        }
        vector<int> stk;
        stk.push_back(i);
        for (int j = 1; j <= m + 1; ++j) {
            while (!stk.empty() && mnh[stk.back()] > mnh[j]) {
                int lasth = mnh[stk.back()];
                debug(i, j, stk.back(), lasth);
                stk.pop_back();
                int num_w = (j - stk.back() - 1);
                int num_h = lasth - mnh[stk.back()];
                ll sum = 1ll * (num_w * (num_w + 1) / 2) * num_h;

                debug(i, j, num_w, num_h, sum);
                cnt += sum;
            }
            if (mnh[stk.back()] != mnh[j]) {
                stk.push_back(j);
            }
        }
    }
    cout << cnt << '\n';
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
