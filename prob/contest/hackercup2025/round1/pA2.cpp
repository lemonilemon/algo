/*
 * Created : 2025-10-19 01:00:00 lemonilemon
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

const int MAXN = 500005;
int a[MAXN];
struct DSU {
    int rt[MAXN], rk[MAXN];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
    int find(int x) { return x == rt[x] ? x : rt[x] = find(rt[x]); }
    bool setunion(int k1, int k2) {
        int r1 = find(k1), r2 = find(k2);
        if (r1 == r2)
            return false;
        if (rk[r1] < rk[r2])
            swap(r1, r2);
        rt[r2] = r1;
        rk[r1] += rk[r2];
        return true;
    }
} dsu;
// solution
void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        edges.push_back({a[i], {0, i}});
    }
    for (int i = 2; i <= n; ++i) {
        edges.push_back({abs(a[i] - a[i - 1]), {i - 1, i}});
    }
    sort(edges.begin(), edges.end());
    dsu.init(n);
    int ans = 0;
    for (auto [w, p] : edges) {
        auto [u, v] = p;
        if (dsu.setunion(u, v)) {
            ans = max(ans, w);
        }
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
