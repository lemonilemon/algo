/* 
 * Created : 2024-08-27 22:36:53 lemonilemon
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
const int MAXN = 1e6 + 5;
int a[MAXN];

// solution
void solve() {
    int n; 
    cin >> n;
    int cur = 0;
    if(n % 4 == 0) { // 11 10 9 2 8 7 6 4 3 1 0 5
        cout << "YES\n";
        for(int i = 0; i < n / 4; ++i) {
            a[cur++] = n - i - 1;
        }
        a[cur++] = n / 4 - 1;
        for(int i = 0; i < n / 4; ++i) {
            a[cur++] = 3 * n / 4 - i - 1;
        }
        for(int i = 0; i < n / 4 - 1; ++i) {
            a[cur++] = n / 2 - i - 2;
        }
        for(int i = 0; i < n / 4 - 1; ++i) {
            a[cur++] = n / 4 - 2 - i;
        }
        a[cur++] = n / 2 - 1;
        for(int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i == n - 1];
        }
    } else if(n % 4 == 1) { // 12 11 10 3 9 8 7 5 4 2 1 0 6
        cout << "YES\n";
        for(int i = 0; i < n / 4; ++i) {
            a[cur++] = n - i - 1;
        }
        a[cur++] = n / 4;
        for(int i = 0; i < n / 4; ++i) {
            a[cur++] = 3 * n / 4 - i;
        }
        for(int i = 0; i < n / 4 - 1; ++i) {
            a[cur++] = n / 2 - i - 1;
        }
        for(int i = 0; i < n / 4 - 1; ++i) {
            a[cur++] = n / 4 - 1 - i;
        }
        a[cur++] = 0;
        a[cur++] = n / 2;
        for(int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i == n - 1];
        }
    } else cout << "NO\n";
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

