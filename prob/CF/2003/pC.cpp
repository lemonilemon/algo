/* 
 * Created : 2024-08-28 10:48:28 lemonilemon
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
const int MAXN = 2e5 + 5;
bool check(string s, int l, int r) {
    if(s[l] == s[r]) return 1;
    for(int i = l; i < r; ++i) {
        if(s[i] == s[i + 1]) continue;
        if(s[i] != s[l] || s[i + 1] != s[r]) return 1;
    }
    return 0;
}
int cnt[26];
// solution
void solve() {
    int n; 
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < 26; ++i) {
        cnt[i] = 0;
    }
    for(auto c : s) {
        ++cnt[c - 'a'];
    }
    string ret;
    for(int j = 0; j < n; ++j) {
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 0) {
                ret += (char)('a' + i);
                --cnt[i];
            }
                
        }
    }
    cout << ret << '\n';
    /*int ans = 0;
    for(int l = 0; l < n; ++l) {
        for(int r = l + 1; r < n; ++r) {
            ans += check(ret, l, r);
        }
    }
    cerr << ans << '\n';*/
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

