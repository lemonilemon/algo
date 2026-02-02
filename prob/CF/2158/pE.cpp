/*
 * Created : 2025-11-29 23:14:43 lemonilemon
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
const ll INF = 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n + 2, vector<ll>(m + 2, INF));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    set<pair<int, int>> holes;
    auto check_min = [&](int x, int y) -> bool {
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            auto p1 = make_tuple(grid[x][y], x, y);
            auto p2 = make_tuple(grid[nx][ny], nx, ny);
            if (p1 > p2)
                return false;
        }
        return true;
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check_min(i, j)) {
                holes.insert({i, j});
            }
        }
    }
    cout << holes.size() << '\n';
    int q;
    cin >> q;
    while (q--) {
        int r, c, x;
        cin >> r >> c >> x;
        grid[r][c] -= x;
        if (check_min(r, c)) {
            holes.insert({r, c});
        } else if (holes.count({r, c})) {
            holes.erase({r, c});
        }
        for (int dir = 0; dir < 4; ++dir) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if (check_min(nx, ny)) {
                    holes.insert({nx, ny});
                } else if (holes.count({nx, ny})) {
                    holes.erase({nx, ny});
                }
            }
        }
        cout << holes.size() << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
