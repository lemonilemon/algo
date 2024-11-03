/*
 * Created : 2024-11-03 20:06:17 lemonilemon
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
ll a[MAXN];
struct Node {
    ll mx, smx, gcd;
    Node(): mx(0), smx(0), gcd(0) {}
    Node(ll v): mx(v), smx(0), gcd(0) {}
    Node operator + (const Node& that) const {
        Node ret = *this;
        vector<ll> v = {mx, smx, that.mx, that.smx};
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if(v.size() >= 2) ret.smx = v[(int)v.size() - 2];
        ret.mx = v.back();
        ret.gcd = __gcd(gcd, that.gcd);
        for(int i = 0; i < (int)v.size() - 2; ++i) {
            ret.gcd = __gcd(v[i], ret.gcd);
        }
        return ret;
    }
} seg[MAXN << 2];
void pull(int v) {
    seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l, int r, int v) {
    if(l == r) {
        seg[v] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
Node query(int ql, int qr, int l, int r, int v) {
    if(ql == l && qr == r) return seg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    else if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, n, 1);
    int Q;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        auto [mx, smx, gcd] = query(l, r, 1, n, 1);
        if(smx == 0) { // all the same
            cout << (mx << 1) << '\n';
            continue;
        }
        // debug(mx, smx, gcd);
        ll ans = max(mx + __gcd(smx, gcd), smx + __gcd(mx, gcd));
        cout << ans << '\n';
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
