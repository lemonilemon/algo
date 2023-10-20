/* 
 * Created : 2023-10-05 17:52:59 lemonilemon
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
const int MAXN = 1e5 + 5;
ll a[MAXN], dif[MAXN];
struct Node {
    ll gcd, sum;
    Node(): gcd(1), sum(0) {}
    Node(ll val): gcd(abs(val)), sum(val) {}
    Node operator + (const Node& that) const {
        Node ret;
        ret.gcd = __gcd(gcd, that.gcd);
        ret.sum = sum + that.sum;
        return ret;
    }
} node[MAXN << 2];
void pull(int v) {
    node[v] = node[v << 1] + node[v << 1 | 1];
}
void build(int l = 1, int r = MAXN, int v = 1) {
    if(l == r) {
        node[v] = Node(dif[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
void modify(int k, int l = 1, int r = MAXN, int v = 1) {
    if(l == r) {
        node[v] = Node(dif[l]);
        return;
    }
    int mid = (l + r) >> 1;
    if(k <= mid) modify(k, l, mid, v << 1);
    else modify(k, mid + 1, r, v << 1 | 1);
    pull(v);
}
Node query(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
    if(ql == l && qr == r) return node[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    else if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    else return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dif[i] = a[i] - a[i - 1];
    }
    build();
    for(int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            ll k;
            cin >> l >> r >> k;
            dif[l] += k;
            dif[r + 1] -= k;
            modify(l);
            modify(r + 1);
        } else {
            int l, r;
            cin >> l >> r;
            if(l == r) {
                cout << query(1, l).sum << '\n';
            } else {
                auto [gcd, _] = query(l + 1, r);
                auto [__, sum] = query(1, l);
                cout << __gcd(gcd, sum) << '\n';
            }
        }
    }
    return;
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

