/* 
 * Created : 2024-09-03 22:46:26 lemonilemon
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
bool check[MAXN][2];
// solution
void solve() {
    int n; 
    cin >> n;
    for(int i = 0; i <= n; ++i) check[i][0] = check[i][1] = 0;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        check[x][y] = 1;
    }
    int cnt2 = 0;
    for(int i = 0; i <= n; ++i) {
        if(check[i][0] && check[i][1]) ++cnt2;
    }
    ll ans = 1ll * cnt2 * (n - 2);
    for(int i = 1; i < n; ++i) {
        if(check[i][0]) ans += check[i + 1][1] && check[i - 1][1];
        if(check[i][1]) ans += check[i + 1][0] && check[i - 1][0];
    }
    cout << ans << '\n';
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

