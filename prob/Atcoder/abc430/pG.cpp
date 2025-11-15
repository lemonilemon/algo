/*
 * Created : 2025-11-01 21:19:27 lemonilemon
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

const int MAXN = 3e5 + 5;
const int MAXX = 64;
struct Node {
    bitset<64> and_bs, or_bs;
    bitset<64> add, rem;
    int mxcnt;
    Node() { mxcnt = 0; }
};
Node seg[MAXN << 2];
void pull(int v) {
    seg[v].and_bs = seg[v << 1].and_bs & seg[v << 1 | 1].and_bs;
    seg[v].or_bs = seg[v << 1].or_bs | seg[v << 1 | 1].or_bs;
    seg[v].mxcnt = max(seg[v << 1].mxcnt, seg[v << 1 | 1].mxcnt);
}
void add_tag(int l, int r, int v, int x) {
    if (seg[v].and_bs[x]) // all x in seg[v]
        return;
    if (!seg[v].or_bs[x]) { // no x in seg[v]
        seg[v].and_bs[x] = 1;
        seg[v].or_bs[x] = 1;
        seg[v].add[x] = 1;
        seg[v].rem[x] = 0;
        ++seg[v].mxcnt;
        return;
    }
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    add_tag(l, mid, v << 1, x);
    add_tag(mid + 1, r, v << 1 | 1, x);
    pull(v);
}
void rem_tag(int l, int r, int v, bitset<64> k) {
    if (!(seg[v].or_bs & k).any()) // no k in seg[v]
        return;
    if ((seg[v].and_bs & k).any()) { // all k in seg[v]
        seg[v].mxcnt -= (seg[v].and_bs & k).count();
        seg[v].and_bs[x] = 0;
        seg[v].or_bs[x] = 0;
        seg[v].add[x] = 0;
        seg[v].rem[x] = 1;
        return;
    }
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    rem_tag(l, mid, v << 1, x);
    rem_tag(mid + 1, r, v << 1 | 1, x);
    pull(v);
}
void push(int v
void modify(int ql, int qr, int x, int l, int r, int v, bool is_add) {
    if (ql == l && qr == r) {
        if (is_add) {
            add_tag(l, r, v, x);
        } else {
            rem_tag(l, r, v, x);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        modify(ql, qr, x, l, mid, v << 1, is_add);
    } else if (ql > mid) {
        modify(ql, qr, x, mid + 1, r, v << 1 | 1, is_add);
    } else {
        modify(ql, mid, x, l, mid, v << 1, is_add);
        modify(mid + 1, qr, x, mid + 1, r, v << 1 | 1, is_add);
    }
    pull(v);
}

int query(int ql, int qr, int l, int r, int v) {
    if (ql == l && qr == r) {
        return seg[v].mxcnt;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(ql, qr, l, mid, v << 1);
    } else if (ql > mid) {
        return query(ql, qr, mid + 1, r, v << 1 | 1);
    } else {
        return max(query(ql, mid, l, mid, v << 1),
                   query(mid + 1, qr, mid + 1, r, v << 1 | 1));
    }
}

// solution
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            int l, r, x;
            cin >> l >> r >> x;
            modify(l, r, x, 1, n, 1, 1);
            break;
        }
        case 2: {
            int l, r, x;
            cin >> l >> r >> x;
            modify(l, r, x, 1, n, 1, 0);
            break;
        }
        case 3: {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << '\n';
            break;
        }
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
