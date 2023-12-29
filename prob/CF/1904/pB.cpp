/* 
 * Created : 2023-12-09 16:15:28 lemonilemon
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
const int MAXN = 1e5 + 5;
ll a[MAXN];
int ord[MAXN];
ll ans[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ord[i] = i;
    }
    sort(ord + 1, ord + n + 1, [](int x, int y) {
        return a[x] < a[y];
    });
    int j = 0;
    ll cnt = 0;
    for(int i = 1; i <= n; ++i) {
        ll cur = a[ord[i]];  
        // debug(cur);
        if(j == i - 1) ++j, cnt += cur;
        while(j < n && a[ord[j + 1]] <= cnt) cnt += a[ord[++j]];
        ans[ord[i]] = j - 1;
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
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

