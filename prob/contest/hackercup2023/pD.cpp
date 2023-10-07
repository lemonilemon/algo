/* 
 * Created : 2023-10-07 19:04:04 lemonilemon
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
const int MAXN = 1e6 + 5, MOD = 1e9 + 7;
int a[MAXN];
void setIO(string s = ""){
    if(s.size()) {
        freopen((s+"in.txt").c_str(),"r",stdin);
        freopen((s+"out.txt").c_str(),"w",stdout);
    }
}
int n; 
struct Node {
    int mn, mnidx, mx, mxidx;
    bool tag;
    Node(): mx(0), mn(MOD - 1), tag(0), mnidx(-1), mxidx(-1) {}
    Node(int val, int idx): mx(val), mn(val), tag(0), mnidx(idx), mxidx(idx) {}
    Node operator + (Node that) {
        Node ret;
        if(that.mn == mn) {
            ret.mn = mn;
            ret.mnidx = min(that.mnidx, mnidx);
        } else if(that.mn < mn) {
            ret.mnidx = that.mnidx;
            ret.mn = that.mn;
        } else {
            ret.mnidx = mnidx;
            ret.mn = mn;
        }
        if(that.mx == mx) {
            ret.mx = mx;
            ret.mxidx = max(that.mxidx, mxidx);
        } else if(that.mx > mx) {
            ret.mxidx = that.mxidx;
            ret.mx = that.mx;
        } else {
            ret.mxidx = mxidx;
            ret.mx = mx;
        }
        return ret;
    }
} seg[MAXN << 2];
void pull(int v) {
    seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void tag(int v) {
    int nmn = MOD - seg[v].mx, nmx = MOD - seg[v].mn;
    seg[v].mn = nmn;
    seg[v].mx = nmx;
    seg[v].tag = !seg[v].tag;
    swap(seg[v].mxidx, seg[v].mnidx);
}
void push(int v) {
    if(seg[v].tag) {
        tag(v << 1);
        tag(v << 1 | 1);
        seg[v].tag = 0;
    }
}
void build(int l = 1, int r = n, int v = 1) {
    if(l == r) {
        seg[v] = Node(a[l], l);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
void modify(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if(ql == l && qr == r) {
        tag(v);
        return;
    }
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) modify(ql, qr, l, mid, v << 1);
    else if(ql > mid) modify(ql, qr, mid + 1, r, v << 1 | 1);
    else {
        modify(ql, mid, l, mid, v << 1);
        modify(mid + 1, qr, mid + 1, r, v << 1 | 1);
    }
    pull(v);
}
Node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if(ql == l && qr == r) return seg[v]; 
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1); 
    return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
// solution
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build();
    int q;
    cin >> q;
    ll sum = 0;
    auto test = query(1, 2);
    debug(test.mx, test.mn, test.mxidx, test.mnidx);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        modify(l, r);
        auto ans = query(1, n);
        debug(ans.mx, ans.mn, ans.mxidx, ans.mnidx);
        sum += ans.mxidx;
    }
    cout << sum << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setIO("pD");
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

