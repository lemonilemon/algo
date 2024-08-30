/* 
 * Created : 2024-08-30 23:29:58 lemonilemon
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

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
bool isleaf[MAXN];
void dfs(int u = 1, int pa = -1) {
    isleaf[u] = true;
    for(auto v : graph[u]) {
        if(v == pa) continue;
        isleaf[u] = false;
        dfs(v, u);
    }
}
// solution
void solve() {
    int n; 
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        isleaf[i] = true;
        graph[i].clear();
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs();
    int cnt0 = 0, cnt1 = 0, und = 0, non = 0;
    string s;
    cin >> s;
    char rt = s[0];
    for(int i = 2; i <= n; ++i) {
        char ch = s[i - 1];
        if(!isleaf[i]) {
            if(ch == '?') ++non;
            continue;
        }
        if(ch == '0') ++cnt0;
        else if(ch == '1') ++cnt1;
        else ++und;
    }
    if(rt == '0') {
        cout << cnt1 + (und + 1) / 2 << '\n';
    } else if(rt == '1') {
        cout << cnt0 + (und + 1) / 2 << '\n';
    } else {
        int ans = max(cnt0, cnt1) + und / 2;
        if(non % 2 == 1) 
            ans = max(ans, min(cnt0, cnt1) + (und + 1) / 2);
        cout << ans << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

