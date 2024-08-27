/* 
 * Created : 2024-08-26 15:06:32 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
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
const int MAXN = 5e4 + 5, SZ = MAXN << 5, MOD = 1e9 + 7, INF = 1e9;
int a[MAXN];
struct Treap {
    Treap *lc, *rc;
    int key, pri;
    ll sum;
    int sz, val;
    bool neg;
    Treap(int key): key(key), pri(rand()), sum(key), sz(1), lc(NULL), rc(NULL), val(key), neg(0) {}
} *root = NULL;
int size(Treap* t) {
    return t? t->sz : 0;
}
ll sum(Treap* t) {
    return t? t->sum : 0;
}
void pull(Treap* t) {
    t->sz = size(t->lc) + size(t->rc) + 1;
    t->sum = sum(t->lc) + sum(t->rc) + t->val;
}
void tag(Treap* t) {
    if(t) {
        t->neg ^= 1;
        t->sum = -t->sum;
        t->val= -t->val;
    }
}
void push(Treap* t) {
    if(t->neg) {
        tag(t->lc);
        tag(t->rc);
        t->neg = 0;
    }
}
Treap* merge(Treap* tl, Treap* tr) {
    if(!tl || !tr) return tl? tl : tr;
    if(tl->pri > tr->pri) {
        push(tl);
        tl->rc = merge(tl->rc, tr);
        pull(tl);
        return tl;
    } else {
        push(tr);
        tr->lc = merge(tl, tr->lc);
        pull(tr);
        return tr;
    }
}
void split(Treap* t, int k, Treap* &tl, Treap* &tr) {
    if(!t) tl = tr = NULL;
    else if(t->key <= k) {
        tl = t;
        push(tl);
        split(t->rc, k, tl->rc, tr);
        pull(tl);
    } else {
        tr = t;
        push(tr);
        split(t->lc, k, tl, tr->lc); 
        pull(tr);
    }
}
ll tot = 0;
void add(int x) {
    int val = a[x];
    tot += val;
    Treap* newnode = new Treap(val);
    Treap* tl, *tr;
    split(root, val - 1, tl, tr);
    debug(sum(tl), size(tl), sum(tr), size(tr));
    tag(tr);
    if(size(tl) & 1) tag(newnode); 
    debug(sum(newnode), size(newnode));
    tr = merge(newnode, tr);
    root = merge(tl, tr);
}
void del(int x) {
    int val = a[x];
    tot -= val;
    Treap* tl, *tr, *mid;
    split(root, val - 1, tl, tr);
    split(tr, val, mid, tr);
    delete mid;
    tag(tr);
    root = merge(tl, tr);
}
// solution
void solve() {
    int n, q; 
    cin >> n >> q;
    struct Query {
        int l, r, id;
    };
    vector<Query> queries;
    vector<int> ans(q);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    const int len = sqrt(n);
    sort(queries.begin(), queries.end(), [&](auto a, auto b) {
        return a.l / len == b.l / len? 
                (a.r == b.r? 0 : ((a.l / len) & 1) ^ (a.r < b.r)) 
                : a.l < b.l;
    });
    int l = 0, r = -1;
    for(auto [ql, qr, id] : queries) {
        while(r < qr) add(++r);
        while(l > ql) add(--l);
        while(r > qr) del(r--);
        while(l < ql) del(l++);
        debug(sum(root), tot);
        ans[id] = ((sum(root) + tot) >> 1) % MOD;
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

