/* 
 * Created : 2024-09-21 10:22:23 lemonilemon
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
char ch[MAXN];
int dp[MAXN];

// solution
void solve() {
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); ++i) {
        ch[i + 1] = s[i];
    }
    dp[0] = 0; 
    int mnidx = 0, smnidx = -1;
    char mnch = ch[1], smnch = 0;
    for(int i = 1; i <= (int)s.size(); ++i) {
        dp[i] = dp[i - 1] + 1;
        if(ch[i] == ch[i - 1]) {
            mnidx = i - 1;
            smnidx = -1;
            mnch = ch[i];
            smnch = 0;
        }
        if((~mnidx) && mnch != ch[i]) {
            dp[i] = min(dp[i], dp[mnidx] + 1);
        } else if((~smnidx) && smnch != ch[i]) {
            dp[i] = min(dp[i], dp[smnidx] + 1);
        }
        if(dp[i] < dp[mnidx]) {
            if(ch[i + 1] == mnch) mnidx = i;
            else smnidx = mnidx, mnidx = i;
            mnch = ch[mnidx + 1];
            smnch = ch[smnidx + 1];
        } else if(dp[i] < dp[smnidx] && ch[i + 1] != mnch) {
            smnidx = i;
            smnch = ch[i + 1];
        }
    }
    cout << dp[s.size()] << '\n';
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

