/* 
 * Created : 2024-08-11 17:53:01 lemonilemon
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
const int MAXN = 9;
// R, L, D, U
const pair<int, int> dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string s;
bool visited[MAXN][MAXN];
int dfs(int x, int y, int step = 0) {
    if(step == 48) { 
        if(x == 7 && y == 1) return 1; 
        return 0;
    }
    if(x == 7 && y == 1) return 0;
    bool check[4];
    for(int i = 0; i < 4; ++i) {
        auto [dx, dy] = dir[i];
        int new_x = x + dx, new_y = y + dy; 
        check[i] = !visited[new_x][new_y];
    }
    if(check[0] && check[1] && !check[2] && !check[3]) {
        return 0;
    } else if(!check[0] && !check[1] && check[2] && check[3]) {
        return 0;
    }
    visited[x][y] = 1; 
    char ch = s[step];
    int ret = 0;
    if(ch == 'R' && check[0]) ret = dfs(x, y + 1, step + 1);
    else if(ch == 'L' && check[1]) ret = dfs(x, y - 1, step + 1);
    else if(ch == 'D' && check[2]) ret = dfs(x + 1, y, step + 1);
    else if(ch == 'U' && check[3]) ret = dfs(x - 1, y, step + 1);
    else if(ch == '?') {
        for(auto [dx, dy] : dir) {
            int new_x = x + dx, new_y = y + dy;
            if(visited[new_x][new_y]) continue;
            ret += dfs(new_x, new_y, step + 1);
        }
    }
    visited[x][y] = 0;
    return ret;
}

// solution
void solve() {
    cin >> s;
    for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < MAXN; ++j) {
            visited[i][j] = 1;
        }
    }
    for(int i = 1; i <= 7; ++i) {
        for(int j = 1; j <= 7; ++j) {
            visited[i][j] = 0;
        }
    }

    cout << dfs(1, 1) << '\n';
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

