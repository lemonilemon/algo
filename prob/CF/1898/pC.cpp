/* 
 * Created : 2023-11-19 15:24:12 lemonilemon
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



// solution
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int left = k - (n + m - 2);
    if(left < 0 || (left & 1)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m - 1; ++j) {
            if(i >= n - 2 && j == m - 2) cout << 'B';
            else cout << (((i + j) & 1)? 'B' : 'R');
            cout << " \n"[j == m - 2];
        }
    }
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i == n - 2 && j >= m - 2) cout << 'R';
            else cout << (((i + j) & 1)? 'B' : 'R');
            cout << " \n"[j == m - 1];
        }
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

