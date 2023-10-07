/* 
 * Created : 2023-10-07 17:52:55 lemonilemon
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
ll x[MAXN];
void setIO(string s = ""){
    if(s.size()) {
        freopen((s+"in.txt").c_str(),"r",stdin);
        freopen((s+"out.txt").c_str(),"w",stdout);
    }
}

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);
    ll dis2;
    if(n == 5) {
        ll dis2_1 = (x[4] + x[3]) - (x[0] + x[2]);
        ll dis2_2 = (x[4] + x[2]) - (x[0] + x[1]);
        dis2 = max(dis2_1, dis2_2);
    } else dis2 = (x[n - 1] + x[n - 2]) - (x[0] + x[1]);
    cout << (dis2 >> 1);
    if(dis2 & 1) cout << ".5";
    cout << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setIO("pA");
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

