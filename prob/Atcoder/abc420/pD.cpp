/*
 * Created : 2025-08-24 20:18:23 lemonilemon
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
const int MAXH = 505, MAXW = 505;
const int INF = 1e9 + 7;
char mat[MAXH][MAXW];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int dis[MAXH][MAXW][2];   // switch or not
int color[MAXH][MAXW][2]; // switch or not
// solution
void solve() {
    int h, w;
    cin >> h >> w;
    queue<tuple<int, int, int>> que; // x, y, switch
    pair<int, int> end;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 'S') {
                que.push({i, j, 0});
            } else if (mat[i][j] == 'G') {
                end = {i, j};
            }
        }
    }
    while (!que.empty()) {
        auto [x, y, sw] = que.front();
        que.pop();
        color[x][y][sw] = 2;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nsw = sw;
            int ndis = dis[x][y][sw] + 1;
            if (nx < 1 || nx > h || ny < 1 || ny > w)
                continue;
            if (mat[nx][ny] == '#')
                continue;
            if (sw == 0 && mat[nx][ny] == 'x')
                continue;
            if (sw == 1 && mat[nx][ny] == 'o')
                continue;
            if (mat[nx][ny] == '?')
                nsw = !sw;
            if (color[nx][ny][nsw])
                continue;
            que.push({nx, ny, nsw});
            color[nx][ny][nsw] = 1;
            dis[nx][ny][nsw] = ndis;
        }
    }
    int mndis = INF;
    for (int i = 0; i < 2; ++i) {
        if (color[end.first][end.second][i]) {
            mndis = min(mndis, dis[end.first][end.second][i]);
        }
    }
    if (mndis != INF) {
        cout << mndis << '\n';
    } else {
        cout << "-1\n";
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
