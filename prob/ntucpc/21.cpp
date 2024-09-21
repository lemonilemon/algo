/* 
 * Created : 2024-09-21 00:00:06 lemonilemon
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
const int MAXN = 1e6 + 5;
bool dp[MAXN][3];
bool backtrack[MAXN][3]; // 1 for +, 0 for -
int mabs(int x) {
    return (x % 3 + 3) % 3;
}


// solution
void solve() {
    string s; 
    cin >> s;
    dp[0][0] = 1;
    for(int i = 1; i <= (int)s.size(); ++i) {
        int d = (s[i - 1] - '0') % 3;
        for(int j = 0; j < 3; ++j) {
            if(dp[i - 1][mabs(j - d)]) {
                backtrack[i][j] = 1;
                dp[i][j] = 1;
            }
            if(dp[i - 1][mabs(j + d)]) {
                backtrack[i][j] = 0;
                dp[i][j] = 1;
            }
        }
    }
    if(dp[s.size()][0] == 0) {
        cout << "NO\n";
        return;
    }
    vector<char> op;
    int cur = 0;
    for(int i = (int)s.size(); i >= 1; --i) {
        if(backtrack[i][cur]) {
            op.push_back('+');
            cur = mabs(cur - (s[i - 1] - '0') % 3);
        } else {
            op.push_back('-');
            cur = mabs(cur + (s[i - 1] - '0') % 3);
        }
    }
    reverse(op.begin(), op.end());
    for(int i = 0; i < (int)s.size(); ++i) {
        if(i >= 1) cout << op[i];
        else if(op[i] == '-') cout << '-';
        cout << s[i];
    }
    cout << '\n';
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

