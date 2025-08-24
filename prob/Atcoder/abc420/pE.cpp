/*
 * Created : 2025-08-24 20:36:31 lemonilemon
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
bool color[MAXN];
struct DSU {
    int rt[MAXN], rk[MAXN], bcnt[MAXN];
    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            rt[i] = i;
            rk[i] = 1;
            bcnt[i] = 0;
        }
    }
    int findroot(int k) { return rt[k] == k ? k : rt[k] = findroot(rt[k]); }
    bool setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if (r1 == r2)
            return 0;
        if (rk[r1] > rk[r2])
            swap(r1, r2);
        rt[r1] = r2;
        bcnt[r2] += bcnt[r1];
        rk[r2] += rk[r1];
        return 1;
    }
};
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            int u, v;
            cin >> u >> v;
            dsu.setunion(u, v);
            break;
        }
        case 2: {
            int u;
            cin >> u;
            int r = dsu.findroot(u);
            dsu.bcnt[r] += (!color[u]) - color[u];
            color[u] = !color[u];
            break;
        }
        case 3: {
            int u;
            cin >> u;
            int r = dsu.findroot(u);
            if (dsu.bcnt[r] > 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
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
