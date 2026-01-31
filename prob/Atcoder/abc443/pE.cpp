/*
 * Created : 2026-01-31 20:32:00 lemonilemon
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
const int MAXN = 3e3 + 5;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> graph[MAXN][MAXN];

// solution
void solve() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i <= n + 1; ++i) {
        grid[i][0] = grid[0][i] = '#';
        grid[n + 1][i] = grid[i][n + 1] = '#';
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            graph[i][j].clear();
            visited[i][j] = false;
        }
    }
    vector<int> lastwall(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
                lastwall[j] = i;
            if (grid[i - 1][j - 1] != '#')
                graph[i][j].push_back({i - 1, j - 1});
            if (grid[i - 1][j + 1] != '#')
                graph[i][j].push_back({i - 1, j + 1});
            if (grid[i - 1][j] != '#')
                graph[i][j].push_back({i - 1, j});
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (lastwall[i] != n) {
            graph[lastwall[i] + 1][i].push_back({lastwall[i], i});
            graph[lastwall[i] + 1][i + 1].push_back({lastwall[i], i});
            graph[lastwall[i] + 1][i - 1].push_back({lastwall[i], i});
        }
        for (int j = lastwall[i] - 1; j >= 1; --j) {
            if (grid[j][i] == '#')
                graph[lastwall[i]][i].push_back({j, i});
        }
    }
    queue<pair<int, int>> que;
    que.push({n, c});
    visited[n][c] = true;
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (auto [nx, ny] : graph[x][y]) {
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                que.push({nx, ny});
            }
        }
    }
    string ans;
    for (int i = 1; i <= n; ++i) {
        ans.push_back(visited[1][i] ? '1' : '0');
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
