/* 
 * Created : 2024-10-14 22:38:58 lemonilemon
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
const int MAXT = 1e5 + 5;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int a[MAXT], b[MAXT];
int diag[MAXN];
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}


// solution
void solve() {
    diag[0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        diag[i] = mmul(diag[i - 1], 2);
    }
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < T; ++i) {
        cin >> b[i];
    }
    for(int i = 0; i < T; ++i) {
        cout << diag[b[i]] << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

