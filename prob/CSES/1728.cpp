/* 
 * Created : 2024-09-21 12:05:37 lemonilemon
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
const int MAXN = 105;
double r[MAXN];


// solution
void solve() {
    double ex = 0; 
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
        for(int j = 1; j < i; ++j) {
            if(r[j] >= r[i]) ex += (2.0 * r[j] - r[i] - 1.0) / (2.0 * r[j]);
            else ex += (1.0 * r[j] - 1.0) / (2.0 * r[i]);
        }
    }
    cerr << fixed << setprecision(8) << ex << '\n';
    ex *= 1e6;
    bool odd = ((int)ex) & 1;
    debug(ex - (int)ex);
    bool ishalf = ex - (int)ex > 0.4 && ex - (int)ex < 0.6;
    debug(odd, ishalf);
    if(!odd && ishalf) ex -= 0.5;
    ex = round(ex) / 1e6;
    cout << fixed << setprecision(6) << ex << '\n';

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

