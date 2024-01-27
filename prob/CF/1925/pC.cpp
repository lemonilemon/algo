/* 
 * Created : 2024-01-27 23:14:40 lemonilemon
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


bool dp[27][26];
char backtrack[27][26]; 
// solution
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    if(m < n) {
        cout << "NO\n";
        for(int i = 0; i < n; ++i) {
            cout << 'a';
        }
        cout << '\n';
        return;
    }
    for(int i = 0 ; i <= n; ++i) {
        for(int j = 0; j < k; ++j) {
            dp[i][j] = 0;
            backtrack[i][j] = 0;
        }
    }
    for(int i = 0; i < k; ++i) {
        dp[0][i] = 1;
    }
    for(auto c : s) {
        int cur = c - 'a';
        for(int i = n; i > 0; --i) {
            if(dp[i][cur]) continue;
            dp[i][cur] = 1;
            for(int j = 0; j < k; ++j) {
                if(!dp[i - 1][j]) {
                    dp[i][cur] = 0;
                    backtrack[i][cur] = j;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < k; ++i) {
        if(!dp[n][i]) {
            cout << "NO\n";
            int len = n, cur = i;
            string ans;
            do {
                ans.push_back(cur + 'a');
                cur = backtrack[len][cur];
                --len;
            } while(len > 0);
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
            return;
        }
    }
    cout << "YES\n";
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

