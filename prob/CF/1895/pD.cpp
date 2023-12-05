/* 
 * Created : 2023-11-22 10:15:14 lemonilemon
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
int a[MAXN], b[MAXN];
int should[32];
int cnt[32];
// solution
void solve() {
    int n;
    cin >> n;
    b[1] = 0;
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
        b[i + 1] = b[i] ^ a[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= __lg(b[i] + 1); ++j) {
            cnt[j] += (b[i] >> j) & 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= __lg(i + 1); ++j) {
            should[j] += (i >> j) & 1;
        }
    }
    for(int i = 0; i <= __lg(n) + 1; ++i) {
        if(should[i] != cnt[i]) b[1] += 1 << i;
    }
    cout << b[1] << ' ';
    for(int i = 2; i <= n; ++i) {
        cout << (b[i] ^ b[1]) << " \n"[i == n];
    }
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

