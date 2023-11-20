/* 
 * Created : 2023-11-20 03:47:54 lemonilemon
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
int sum[MAXN], dif[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    ll beauty = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i) {
        sum[i] = a[i] + b[i];
        dif[i] = a[i] - b[i];
        beauty += abs(dif[i]);
    }
    ll mxans = beauty;
    ll mxsum = -1e18, mxdif = -1e18;
    for(int t = 0; t < 2; ++t) {
        for(int i = 1; i <= n; ++i) {
            mxsum = max(beauty - abs(dif[i]) + sum[i], mxsum);
            mxdif = max(beauty - abs(dif[i]) + dif[i], mxdif);
            mxans = max(mxsum - abs(dif[i]) - sum[i], mxans);
            mxans = max(mxdif - abs(dif[i]) + dif[i], mxans);
        }
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + n + 1);
    }
    cout << mxans << '\n';
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

