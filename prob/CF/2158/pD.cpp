/*
 * Created : 2025-11-29 22:52:59 lemonilemon
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

// solution
vector<vector<pair<int, pair<int, int>>>> graph(1 << 4);
const int INF = 1e9;
int dis[1 << 4][1 << 4];
pair<int, pair<int, int>> from[1 << 4][1 << 4];
void init() {
    for (int i = 0; i < (1 << 4); ++i) {
        for (int l = 0; l < 4; ++l) {
            for (int r = l + 1; r < 4; ++r) {
                bool flag = 1;
                int ni = i;
                for (int j = 0; j < (r - l + 1) / 2; ++j) {
                    int nl = l + j, nr = r - j;
                    if (((i >> nl) & 1) != ((i >> nr) & 1)) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    continue;
                for (int j = l; j <= r; ++j) {
                    ni ^= (1 << j);
                }
                // debug(i, ni, l, r);
                graph[i].push_back({ni, {l, r}});
            }
        }
    }
    for (int i = 0; i < (1 << 4); ++i) {
        for (int j = 0; j < (1 << 4); ++j) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for (int i = 0; i < (1 << 4); ++i) {
        queue<int> que;
        int color[1 << 4]{};
        que.push(i);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto [v, op] : graph[u]) {
                if (color[v])
                    continue;
                color[v] = 1;
                que.push(v);
                dis[i][v] = dis[i][u] + 1;
                from[i][v] = {u, op};
            }
        }
    }
    for (int i = 0; i < (1 << 4); ++i) {
        for (int j = 0; j < (1 << 4); ++j) {
            assert(dis[i][j] <= 8);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<bool> s, t;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s.push_back(c == '1');
    }
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        t.push_back(c == '1');
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 4; ++i) {
        if (s[i] == t[i])
            continue;
        if (s[i] == s[i + 1]) {
            ans.push_back({i + 1, i + 2});
            s[i] = !s[i];
            s[i + 1] = !s[i + 1];
            continue;
        }
        if (s[i + 1] != s[i + 2]) { // 010 or 101
            ans.push_back({i + 1, i + 3});
            s[i] = !s[i];
            s[i + 1] = !s[i + 1];
            s[i + 2] = !s[i + 2];
            continue;
        }
        ans.push_back({i + 2, i + 3});
        ans.push_back({i + 1, i + 2});
        s[i] = !s[i];
        s[i + 2] = !s[i + 2];
    }
    int u = 0, v = 0;
    for (int i = n - 1; i >= n - 4; --i) {
        u <<= 1;
        v <<= 1;
        u |= s[i];
        v |= t[i];
    }
    stack<pair<int, int>> stk;
    while (v != u) {
        auto [nv, op] = from[u][v];
        op.first += n - 3;
        op.second += n - 3;
        stk.push(op);
        v = nv;
    }
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
