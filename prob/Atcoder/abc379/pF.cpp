/*
 * Created : 2024-11-09 20:34:11 lemonilemon
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
int h[MAXN];
int seg[MAXN << 2];
void pull(int v) {
    seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
void build(int l, int r, int v) {
    if(l == r) {
        seg[v] = h[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
int query(int ql, int qr, int l, int r, int v) {
    if(ql == l && qr == r) return seg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    return max(query(ql, mid, l, mid, v << 1), query(mid + 1, qr, mid + 1, r, v << 1 | 1));
}
const int MAXQ = 2e5 + 5;
int ans[MAXQ];
vector<pair<int, int> > queries[MAXQ];
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    build(1, n, 1);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    vector<int> stk;
    for(int r = n; r > 0; --r) {
        for(auto [l, idx] : queries[r]) {
            int need = query(l + 1, r, 1, n, 1);
            auto p = upper_bound(stk.begin(), stk.end(), need, greater<int>());
            ans[idx] = p - stk.begin();
        }
        while(!stk.empty() && h[r] > stk.back()) stk.pop_back();
        stk.push_back(h[r]);
    }
    for(int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
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
