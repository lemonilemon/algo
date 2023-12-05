/* 
 * Created : 2023-11-22 09:36:51 lemonilemon
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


vector<string> sl[6];
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        sl[s.size()].push_back(s);
    }
    ll ans = 0;
    for(int len = 2; len <= 10; len += 2) {
        for(int l1 = 1; l1 <= len / 2; ++l1) {
            int l2 = len - l1; // l2 > l1
            if(l2 > 5) continue;
            map<int, int> vals;
            for(auto& s : sl[l2]) {
                int val = 0;
                for(int i = 0; i < l2; ++i) {
                    if(i < l2 - len / 2) val -= s[i] - '0';
                    else val += s[i] - '0';
                }
                if(vals.count(val)) ++vals[val];
                else vals[val] = 1;
            }
            for(auto& s : sl[l1]) {
                int val = 0;
                for(int i = 0; i < l1; ++i) {
                    val += s[i] - '0';
                }
                if(vals.count(val)) ans += vals[val];
            }
        }
    }
    for(int len = 2; len <= 10; len += 2) {
        for(int l2 = 1; l2 < len / 2; ++l2) {
            int l1 = len - l2; // l1 > l2
            if(l1 > 5) continue;
            map<int, int> vals;
            for(auto s : sl[l1]) {
                int val = 0;
                for(int i = 0; i < l1; ++i) {
                    if(i < len / 2) val += s[i] - '0';
                    else val -= s[i] - '0';
                }
                if(vals.count(val)) ++vals[val];
                else vals[val] = 1;
            }
            for(auto s : sl[l2]) {
                int val = 0;
                for(int i = 0; i < l2; ++i) {
                    val += s[i] - '0';
                }
                if(vals.count(val)) ans += vals[val];
            }
        }
    }
    cout << ans << '\n';
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

