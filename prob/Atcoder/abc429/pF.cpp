/*
 * Created : 2025-10-25 22:04:24 lemonilemon
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
const int INF = 1e9;
struct Node {
    int val[3][3];
    Node() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                val[i][j] = INF;
            }
        }
    }
    Node(int x) {
        debug(x);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                val[i][j] = INF;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if ((x >> i) & 1) { // wall
                continue;
            }
            for (int j = 0; j < 3; ++j) {
                if ((x >> j) & 1) { // wall
                    continue;
                }
                if (i == j) {
                    val[i][j] = 1;
                } else if (abs(i - j) == 1) {
                    val[i][j] = 2;
                } else if (abs(i - j) == 2) {
                    val[i][j] = (x & 2) ? INF : 3;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                debug(i, j, val[i][j]);
            }
        }
    }
    Node operator+(const Node &other) const {
        Node ret;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    ret.val[i][j] =
                        min(ret.val[i][j], val[i][k] + other.val[k][j]);
                }
            }
        }
        return ret;
    }
} seg[MAXN << 2];
int a[MAXN];
void pull(int v) { seg[v] = seg[v << 1] + seg[v << 1 | 1]; }
void build(int l, int r, int v) {
    if (l == r) {
        seg[v] = Node(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
    return;
}
void modify(int x, int idx, int l, int r, int v) {
    if (l == r) {
        seg[v] = Node(x);
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) {
        modify(x, idx, l, mid, v << 1);
    } else {
        modify(x, idx, mid + 1, r, v << 1 | 1);
    }
    pull(v);
    return;
}
// solution
void solve() {
    int n;
    cin >> n;
    for (int r = 0; r < 3; ++r) {
        for (int i = 1; i <= n; ++i) {
            char tmp;
            cin >> tmp;
            a[i] += ((int)(tmp == '#') << r);
        }
    }
    build(1, n, 1);
    int q;
    cin >> q;
    while (q--) {
        int r, c;
        cin >> r >> c;
        a[c] ^= (1 << (r - 1));
        modify(a[c], c, 1, n, 1);
        if (seg[1].val[0][2] == INF) {
            cout << "-1\n";
            continue;
        }
        cout << seg[1].val[0][2] - 1 << '\n';
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
