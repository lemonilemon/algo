/*
 * Created : 2024-11-30 22:43:35 lemonilemon
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
map<char, int> mp;
char ch[] = "RDUL?";
pair<int, int> dir[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int MAXN = 1005, MAXM = 1005;
bool trap[MAXN][MAXM];
int vis[MAXN][MAXM];
int mat[MAXN][MAXM];
void dfs(int x, int y) {
    // cerr << x << ' ' << y << '\n';
    vis[x][y] = 1;
    auto [dx, dy] = dir[mat[x][y]];
    int nx = x + dx, ny = y + dy;
    if (vis[nx][ny] == 0) {
        if (mat[nx][ny] != 4) {
            dfs(nx, ny);
        }
        if (!trap[nx][ny])
            trap[x][y] = 0;
    } else if (vis[nx][ny] == 2) {
        if (!trap[nx][ny])
            trap[x][y] = 0;
    }
    vis[x][y] = 2;
}

// solution
void solve() {
    for (int i = 0; i < 5; ++i) {
        mp[ch[i]] = i;
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            trap[i][j] = 0;
            vis[i][j] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            mat[i][j] = mp[c];
            trap[i][j] = 1;
            vis[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mat[i][j] != 4 && vis[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mat[i][j] == 4) {
                trap[i][j] = 0;
                for (auto [dx, dy] : dir) {
                    int nx = i + dx, ny = j + dy;
                    if (trap[nx][ny])
                        trap[i][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += trap[i][j];
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
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
