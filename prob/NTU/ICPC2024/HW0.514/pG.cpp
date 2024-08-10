/* 
 * Created : 2024-07-27 00:27:59 lemonilemon
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
int a[MAXN], b[MAXN];
int n, p;

bool check(double k) {
    double sum = 0;
    for(int i = 1; i <= n; ++i) {
        double least = (a[i] - b[i] / k) / p;
        if(least >= 0) sum += least;
    }
    return sum <= 1;
    
}

// solution
void solve() {
    cin >> n >> p;

    ll asum = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        asum += a[i]; 
    } 

    if(asum <= p) {
        cout << "-1\n";
        return;
    }

    double l = 0, r = 1e18; 

    while(r - l > 1e-8) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid; 
    }

    cout << fixed << setprecision(8) << l << '\n';
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

