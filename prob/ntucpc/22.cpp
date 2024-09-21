/* 
 * Created : 2024-09-21 09:14:36 lemonilemon
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
const int MAXN = 1e6 + 5;
ll top[MAXN << 2], bot[MAXN << 2];
ll sum[MAXN << 2];
void build(int l, int r, int v) {
    top[v] = bot[v] = -1;
    sum[v] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
}
void push(int v) {
    if(~top[v]) {
        if(~top[v << 1]) sum[v << 1] += bot[v] ^ top[v << 1];
        sum[v << 1] += sum[v];
        top[v << 1] = top[v];
        if(!(~bot[v << 1])) bot[v << 1] = bot[v];
        if(~top[v << 1 | 1]) sum[v << 1 | 1] += bot[v] ^ top[v << 1 | 1];
        sum[v << 1 | 1] += sum[v];
        top[v << 1 | 1] = top[v];
        if(!(~bot[v << 1 | 1])) bot[v << 1 | 1] = bot[v];
        top[v] = bot[v] = -1;
        sum[v] = 0;
    }
}

void modify(int ql, int qr, ll val, int l, int r, int v) {
    debug(ql, qr, val, l, r, v);
    if(ql == l && qr == r) {
        if(~bot[v]) {
            sum[v] += top[v] ^ val;
            top[v] = val;
        } else {
            bot[v] = top[v] = val;
            sum[v] = 0;
        }
        return;
    }
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) {
        modify(ql, qr, val, l, mid, v << 1);
    } else if(ql > mid) {
        modify(ql, qr, val, mid + 1, r, v << 1 | 1);
    } else {
        modify(ql, mid, val, l, mid, v << 1);
        modify(mid + 1, qr, val, mid + 1, r, v << 1 | 1);
    }
}
ll query(int p, int l, int r, int v) {
    debug(l, r, v, top[v], bot[v], sum[v]);
    if(l == r) return sum[v];
    push(v);
    int mid = (l + r) >> 1;
    if(p <= mid) return query(p, l, mid, v << 1);
    else return query(p, mid + 1, r, v << 1 | 1);
}


// solution
void solve() {
    int n, q; 
    cin >> n >> q;
    build(1, n, 1);
    for(int i = 1; i <= q; ++i) {
        int op;
        cin >> op;
        switch(op) {
            case 1: {
                int l, r;
                ll x;
                cin >> l >> r >> x;
                modify(l, r, x, 1, n, 1);
                break;
            }
            case 2: {
                int p;
                cin >> p;
                cout << query(p, 1, n, 1) << '\n';
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
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

