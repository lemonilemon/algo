/*
 * Created : 2024-11-15 11:00:49 lemonilemon
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
const int maxn = 1e6 + 5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<ll> v;
struct lichao { // maxn: range
    struct line {
        ll a, b;
        line() : a(0), b(LINF) {} // or b(LINF) if min
        line(ll a, ll b) : a(a), b(b) {}
        ll operator()(ll x) { return a * v[x] + b; } // v[x]
    } arr[maxn << 2];
    void _insert(int l, int r, int id, line x) {
        int m = (l + r) >> 1;
        if (arr[id](m) > x(m))
            swap(arr[id], x);
        if (l == r - 1)
            return;
        if (arr[id].a > x.a)
            _insert(m, r, id << 1 | 1, x);
        else
            _insert(l, m, id << 1, x);
    } // change to > if query min
    // maxn ‐> v.size() after li san hua
    void insert(ll a, ll b) { _insert(0, v.size(), 1, line(a, b)); }
    void insert(int l, int r, int id, int ql, int qr, ll a, ll b) {
        if (ql >= qr)
            return;
        if (ql == l && qr == r) {
            _insert(l, r, id, line(a, b));
            return;
        }
        int mid = (l + r) >> 1;
        if (qr <= mid)
            insert(l, mid, id << 1, ql, qr, a, b);
        else if (ql >= mid)
            insert(mid, r, id << 1 | 1, ql, qr, a, b);
        else {
            insert(l, mid, id << 1, ql, mid, a, b);
            insert(mid, r, id << 1 | 1, mid, qr, a, b);
        }
    }
    ll que(int l, int r, int id, int p) {
        if (l == r - 1)
            return arr[id](p);
        int m = (l + r) >> 1;
        if (p < m)
            return min(arr[id](p), que(l, m, id << 1, p));
        return min(arr[id](p), que(m, r, id << 1 | 1, p));
    } // chnage to min if query min
    // maxn ‐> v.size() after li san hua
    ll que(int p) { return que(0, v.size(), 1, p); }
} tree;
struct Seg {
    int l, r;
    ll a, b;
};
struct Query {
    int op;
    Seg seg;
};
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    vector<Seg> segs(n);
    for (auto &[l, r, a, b] : segs) {
        cin >> l >> r >> a >> b;
        v.push_back(l);
        v.push_back(r);
    }
    vector<Query> queries(q);
    for (auto &[op, seg] : queries) {
        cin >> op;
        if (op == 0) {
            cin >> seg.l >> seg.r >> seg.a >> seg.b;
            v.push_back(seg.l);
            v.push_back(seg.r);
        } else {
            cin >> seg.l;
            v.push_back(seg.l);
        }
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto [l, r, a, b] : segs) {
        l = lower_bound(v.begin(), v.end(), l) - v.begin();
        r = lower_bound(v.begin(), v.end(), r) - v.begin();
        tree.insert(0, v.size(), 1, l, r, a, b);
    }
    for (auto [op, seg] : queries) {
        if (op == 0) {
            seg.l = lower_bound(v.begin(), v.end(), seg.l) - v.begin();
            seg.r = lower_bound(v.begin(), v.end(), seg.r) - v.begin();
            tree.insert(0, v.size(), 1, seg.l, seg.r, seg.a, seg.b);
        } else {
            seg.l = lower_bound(v.begin(), v.end(), seg.l) - v.begin();
            ll val = tree.que(seg.l);
            if (val == LINF)
                cout << "INFINITY\n";
            else
                cout << val << '\n';
        }
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
