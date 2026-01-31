/*
 * Created : 2026-01-31 20:45:45 lemonilemon
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
const int MAXN = 3e6 + 5;
bool visited[MAXN][10];
// solution
void solve() {
    int n;
    cin >> n;
    queue<pair<int, string>> que;
    for (int i = 1; i <= 9; ++i) {
        que.push({i % n, to_string(i)});
        visited[i % n][i] = true;
    }
    while (!que.empty()) {
        auto [mod, num] = que.front();
        que.pop();
        if (mod == 0) {
            cout << num << '\n';
            return;
        }
        int last_digit = num.back() - '0';
        for (int i = last_digit; i <= 9; ++i) {
            int nxt_mod = (1ll * mod * 10 + i) % n;
            if (visited[nxt_mod][i])
                continue;
            visited[nxt_mod][i] = true;
            que.push({nxt_mod, num + to_string(i)});
        }
    }
    cout << -1 << '\n';
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
