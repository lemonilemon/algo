/* 
 * Created : 2023-09-25 22:38:55 lemonilemon
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
#endif

// constants
const int MAXN = 55;
set<int> s[MAXN];
set<int> all;
// solution
void solve() {
    int n;
    cin >> n;
    all.clear();
    for(int i = 0; i < n; ++i) {
        s[i].clear();
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int val;
            cin >> val;
            s[i].insert(val);
            all.insert(val);
        }
    }
    int mx = 0;
    for(auto ex : all) {
        set<int> ans;
        for(int i = 0; i < n; ++i) {
            if(s[i].count(ex)) continue;
            for(auto val : s[i]) {
                ans.insert(val);
            }
        }
        mx = max(mx, (int)ans.size());
    }
    cout << mx << '\n';
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

