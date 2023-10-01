/* 
 * Created : 2023-09-30 14:33:48 lemonilemon
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
ll INF = 1e18 + 9;
ll dis[1 << 8][1 << 8];
vector<pair<int, int> > op[4];
// solution
void init() {
    int n = 1 << 8;
    for(int x = 0; x < 2; ++x) {
        for(int y = 0; y < 2; ++y) {
            for(int m = 0; m < 2; ++m) {
                int orival = (x << 1) | y | (m << 2);
                int nx = x & y, ny = y;
                int nval = (nx << 1) | ny | (m << 2);
                op[0].push_back(make_pair(orival, nval));
                nx = x | y, ny = y;
                nval = (nx << 1) | ny | (m << 2);
                op[1].push_back(make_pair(orival, nval));
                nx = x, ny = x ^ y;
                nval = (nx << 1) | ny | (m << 2);
                op[2].push_back(make_pair(orival, nval));
                nx = x, ny = y ^ m;
                nval = (nx << 1) | ny | (m << 2);
                op[3].push_back(make_pair(orival, nval));
            }
        }
    }
    /*for(int i = 0; i < 4; ++i) {
        debug(i);
        for(auto [u, v] : op[i]) {
            debug(u, v);
        }
    }*/
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dis[i][j] = INF;
        }
    }
    for(int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 4; ++j) {
            int to = 0;
            for(auto [u, v] : op[j]) {
                to |= ((bool)(i & (1 << u))) << v;
            }
            if(i == 23) debug(i, to);
            dis[i][to] = min(dis[i][to], 1ll);
        }
    }
    /* for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            debug(i, j, dis[i][j]);
        }
    } */
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
void solve() {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int from = 0, to = 0;
    for(int i = 0; i < 30; ++i) {
        bool bit_a = a & (1 << i);
        bool bit_b = b & (1 << i);
        bool bit_c = c & (1 << i);
        bool bit_d = d & (1 << i);
        bool bit_m = m & (1 << i);
        from |= 1 << ((bit_a << 1) | bit_b | (bit_m << 2));
        to |= 1 << ((bit_c << 1) | bit_d | (bit_m << 2));
        if(from == 0 && to != 0) {
            cout << "-1\n";
            return;
        }
        if((from == 2 || from == 3) && to == 1) {
            cout << "-1\n";
            return;
        }
    }
    debug(from, to);
    if(dis[from][to] == INF) cout << "-1\n";
    else cout << dis[from][to] << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

