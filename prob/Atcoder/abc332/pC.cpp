/* 
 * Created : 2023-12-10 12:06:44 lemonilemon
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



// solution
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i <= 1000; ++i) {
        int plain = m, logo = i;
        bool flag = 1;
        for(auto c : s) {
            if(c == '0') {
                plain = m;
                logo = i; 
            } else if(c == '1') {
                if(plain) --plain;
                else {
                    if(logo) --logo;
                    else {
                        flag = 0;
                        break;
                    }
                }
            } else {
                if(logo) --logo;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) {
            cout << i << '\n';
            return;
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

