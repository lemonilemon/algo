/*
 * Created : 2024-11-15 10:20:55 lemonilemon
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
const int MAXN = 5e5 + 5;
const int MOD = 998244353;
int madd(int a, int b) { return (a + b) % MOD; }
int mmul(int a, int b) { return (1LL * a * b) % MOD; }
struct Node {
    int val;
    int sz;
    int addlazy, mullazy;
    Node() : val(0), sz(1), addlazy(0), mullazy(1) {}
    Node(int _val) : val(_val), sz(1), addlazy(0), mullazy(1) {}
    Node operator+(const Node &that) {
        Node ret;
        ret.val = madd(val, that.val);
        ret.sz = sz + that.sz;
        return ret;
    }
} seg[MAXN << 2];
int a[MAXN];
void pull(int v) { seg[v] = seg[v << 1] + seg[v << 1 | 1]; }
void tag(int v, int mullazy, int addlazy) {
    seg[v].val = madd(mmul(seg[v].val, mullazy), mmul(addlazy, seg[v].sz));
    seg[v].mullazy = mmul(seg[v].mullazy, mullazy);
    seg[v].addlazy = madd(mmul(seg[v].addlazy, mullazy), addlazy);
}
void push(int v) {
    tag(v << 1, seg[v].mullazy, seg[v].addlazy);
    tag(v << 1 | 1, seg[v].mullazy, seg[v].addlazy);
    seg[v].addlazy = 0;
    seg[v].mullazy = 1;
}
void build(int l, int r, int v) {
    if (l == r) {
        seg[v] = Node(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
    return;
}
void modify(int ql, int qr, int m, int b, int l, int r, int v) {
    if (ql == l && qr == r) {
        tag(v, m, b);
        return;
    }
    push(v);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        modify(ql, qr, m, b, l, mid, v << 1);
    else if (ql > mid)
        modify(ql, qr, m, b, mid + 1, r, v << 1 | 1);
    else {
        modify(ql, mid, m, b, l, mid, v << 1);
        modify(mid + 1, qr, m, b, mid + 1, r, v << 1 | 1);
    }
    pull(v);
}
Node query(int ql, int qr, int l, int r, int v) {
    if (ql == l && qr == r)
        return seg[v];
    push(v);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(ql, qr, l, mid, v << 1);
    else if (ql > mid)
        return query(ql, qr, mid + 1, r, v << 1 | 1);
    else
        return query(ql, mid, l, mid, v << 1) +
               query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}

// solution
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, n, 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r, m, b;
            cin >> l >> r >> m >> b;
            ++l;
            modify(l, r, m, b, 1, n, 1);
        } else {
            int l, r;
            cin >> l >> r;
            ++l;
            cout << query(l, r, 1, n, 1).val << '\n';
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
