/*
 * Created : 2024-11-15 11:58:59 lemonilemon
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
const int MAXN = 2e5 + 5;
struct Node {
    int sum, l, r;
    Node() : sum(0), l(0), r(0) {}
} nodes[MAXN << 5];
void pull(int v) {
    int l = nodes[v].l, r = nodes[v].r;
    nodes[v].sum = nodes[l].sum + nodes[r].sum;
}
int curnode;
int modify(int now, int l, int r, int pos) {
    int dir = ++curnode;
    nodes[dir] = nodes[now];
    if (l == r) {
        ++nodes[dir].sum;
        return dir;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        nodes[dir].l = modify(nodes[now].l, l, mid, pos);
    else
        nodes[dir].r = modify(nodes[now].r, mid + 1, r, pos);
    pull(dir);
    return dir;
}
int binsearch(int now, int past, int l, int r, int k) {
    if (l == r)
        return l;
    int diff = nodes[now].sum - nodes[past].sum;
    if (diff <= k)
        return -1;
    int ldiff = nodes[nodes[now].l].sum - nodes[nodes[past].l].sum;
    if (ldiff > k)
        return binsearch(nodes[now].l, nodes[past].l, l, (l + r) >> 1, k);
    else
        return binsearch(nodes[now].r, nodes[past].r, ((l + r) >> 1) + 1, r,
                         k - ldiff);
}
int a[MAXN];
int idx[MAXN], ridx[MAXN];
int rt[MAXN];
vector<int> v;
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; ++i) {
        idx[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        rt[i] = modify(rt[i - 1], 1, n, idx[i]);
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int id = binsearch(rt[r], rt[l], 1, n, k);
        cout << v[id - 1] << '\n';
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
