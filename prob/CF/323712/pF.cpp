/* 
 * Created : 2023-10-06 03:45:14 lemonilemon
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
const int MAXN = 3005, MAXQ = 3e5 + 5;
ll bit[MAXQ];
ll query(int k) {
    ll ret = 0;
    for(; k > 0; k ^= k & -k) ret += bit[k];
    return ret;
}
void modify(int k, int val) {
    for(; k < MAXQ; k += k & -k) bit[k] += val;
}
vector<pair<int, int> > quest[MAXN]; // quest[l] = (r, t)                 
vector<tuple<int, int, int> > event[MAXN]; // event[l] = (r, w, t)
pair<int, int> add[MAXN]; // add[r] = (w, t)
int ans[MAXQ];
// solution
void solve() {
    int q; 
    cin >> q;
    int t = 0;
    for(int i = 1; i <= q; ++i) {
        int c;
        cin >> c;
        if(c == 1) {
            int l, r, w;
            cin >> l >> r >> w;
            event[l].push_back({r, w, ++t});
        } else {
            int l, r;
            cin >> l >> r;
            quest[l].push_back({r, t});
        }
    }
    for(int l = MAXN - 1; l > 0; --l) {
        vector<int> que[MAXN]; // query[r] = t
        for(auto [r, t] : quest[l]) {
            que[r].push_back(t);
        }
        for(auto [r, w, t] : event[l]) {
            
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

