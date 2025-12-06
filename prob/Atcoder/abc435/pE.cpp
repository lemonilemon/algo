/*
 * Created : 2025-12-06 20:19:13 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

// Docs for AC-library:
// https://atcoder.github.io/ac-library/production/document_en/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
// using namespace atcoder;
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

// using mint = modint;
// using mint = modint1000000007;
// using mint = modint998244353;
// constants
struct Node {
    int sz, val;
    bool lazy;
    Node *left, *right;
    Node() : val(0), sz(0), lazy(0), left(nullptr), right(nullptr) {}
    Node(int _sz) : sz(_sz), val(0), lazy(0), left(nullptr), right(nullptr) {}
    Node &operator=(const Node &other) {
        this->val = other.val;
        this->sz = other.sz;
        return *this;
    }
    Node operator+(const Node &other) const {
        Node ret;
        ret.sz = this->sz + other.sz;
        ret.val = this->val + other.val;
        return ret;
    }
    Node &getleft() {
        if (left == nullptr) {
            debug("new left", sz - sz / 2);
            left = new Node(sz - sz / 2);
        }
        return *left;
    }
    Node &getright() {
        if (right == nullptr) {
            debug("new right", sz / 2);
            right = new Node(sz / 2);
        }
        return *right;
    }
} *root;

void pull(Node &node) {
    if (node.sz <= 1)
        return;
    node = node.getleft() + node.getright();
}
void tag(Node &node) {
    node.lazy = 1;
    node.val = node.sz;
}
void push(Node &node) {
    if (node.sz <= 1)
        return;
    if (node.lazy) {
        tag(node.getleft());
        tag(node.getright());
        node.lazy = 0;
    }
}
Node query(Node &node, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) {
        return node;
    }
    push(node);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(node.getleft(), l, mid, ql, qr);
    else if (ql > mid)
        return query(node.getright(), mid + 1, r, ql, qr);
    return query(node.getleft(), l, mid, ql, mid) +
           query(node.getright(), mid + 1, r, mid + 1, qr);
}
void modify(Node &node, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) {
        debug("tagged", l, r);
        tag(node);
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        modify(node.getleft(), l, mid, ql, qr);
    else if (ql > mid)
        modify(node.getright(), mid + 1, r, ql, qr);
    else {
        modify(node.getleft(), l, mid, ql, mid);
        modify(node.getright(), mid + 1, r, mid + 1, qr);
    }
    debug("before pull", l, r, node.val, node.sz);
    debug("left", l, mid, node.getright().val, node.getright().sz);
    debug("right", mid + 1, r, node.getright().val, node.getright().sz);
    pull(node);
    debug(l, r, node.val, node.sz);
}

// solution
void solve() {
    int n, q;
    cin >> n >> q;
    root = new Node(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        modify(*root, 1, n, l, r);
        cout << n - query(*root, 1, n, 1, n).val << '\n';
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
