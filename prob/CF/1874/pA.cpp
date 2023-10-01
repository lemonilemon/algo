/* 
 * Created : 2023-09-30 14:27:15 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


// #define LOCAL

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
const int MAXN = 55, MAXM = 55;
ll a[MAXN], b[MAXM];

// solution
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    bool sta = 1;
    int cnt = 0;
    while(k) {
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        ll suma = 0;
        for(int i = 1; i <= n; ++i) {
            suma += a[i];
        }
        if(sta) {
            if(a[n] <= b[m] && a[1] <= b[1]) { // b max, a min
                if(k & 1) cout << suma + b[m] - a[1] << '\n';
                else cout << suma << '\n'; 
                debug(cnt);
                return;
            }
        } else {
            if(b[m] <= a[n] && b[1] <= a[1]) {
                if(k & 1) cout << suma - a[n] + b[1] << '\n';
                else cout << suma << '\n'; 
                debug(cnt);
                return;
            }
        }
        if(sta) {
            if(a[1] < b[m]) swap(a[1], b[m]); 
        } else {
            if(b[1] < a[n]) swap(a[n], b[1]); 
        } 
        ++cnt;
        --k;
        sta = !sta;
    }
    debug(cnt);
    ll suma = 0;
    for(int i = 1; i <= n; ++i) {
        suma += a[i];
    }
    cout << suma << '\n';
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

