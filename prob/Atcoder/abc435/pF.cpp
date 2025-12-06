/*
 * Created : 2025-12-06 21:04:37 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

// Docs for AC-library:
// https://atcoder.github.io/ac-library/production/document_en/
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

// using mint = modint;
// using mint = modint1000000007;
// using mint = modint998244353;
// constants

vector<int> p, pos;
vector<vector<int>> st;
int get_max(int l, int r) {
    int dis = r - l + 1;
    int lg_dis = __lg(dis);
    return max(st[l][lg_dis], st[r - (1 << lg_dis) + 1][lg_dis]);
}
ll dq(int l, int r) {
    int mx = get_max(l, r);
    int mxidx = pos[mx];
    ll lval = 0, rval = 0;
    if (mxidx != l) {
        int lmx_idx = pos[get_max(l, mxidx - 1)];
        lval = dq(l, mxidx - 1) + (mxidx - lmx_idx);
    }
    if (mxidx != r) {
        int rmx_idx = pos[get_max(mxidx + 1, r)];
        rval = dq(mxidx + 1, r) + (rmx_idx - mxidx);
    }
    return max(lval, rval);
}

// solution
void solve() {
    int n;
    cin >> n;
    p.resize(n + 1);
    pos.resize(n + 1);
    st.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        st[i].resize(__lg(n) + 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        st[i][0] = p[i];
        pos[p[i]] = i;
    }
    for (int j = 1; j <= __lg(n); ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    cout << dq(1, n) << '\n';
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
