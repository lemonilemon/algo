/* 
 * Created : 2023-10-05 16:17:51 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


//#define LOCAL

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
const int MAXX = 1e6 + 5;
int BIT[MAXX];
void modify(int k) {
    for(; k < MAXX; k += k & -k) ++BIT[k];
}
int kth(int k) {
    int ret = 0;
    for(int i = __lg(MAXX - 1); i >= 0; --i) {
        int cur = 1 << i;
        if(ret + cur < MAXX && BIT[ret + cur] < k) {
            debug((ret + cur));
            k -= BIT[ret += cur];
        }
    }
    return ret + 1;
}

// solution
void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            cin >> x;
            modify(x);
            ++cnt;
        } else{
           int s = (cnt + 1) >> 1;
           cout << kth(s) << '\n';
        }
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

