/* 
 * Created : 2024-10-14 23:07:54 lemonilemon
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
const int MAXN = 2e6 + 5;
const int MAXM = 5005;
int r[MAXN];
int dp[MAXM][MAXM]; // with j intelligence
// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    vector<int> inte, stre;
    int cur = 0;
    for(int i = 1; i <= m; ++i) {
        dp[0][i] = -1e9;
    }
    for(int i = 0; i < n; ++i) {
        cin >> r[i];
        if(r[i] == 0) {
            ++cur;
            sort(inte.begin(), inte.end());
            sort(stre.begin(), stre.end());
            for(int j = 0; j <= m; ++j) {
                dp[cur][j] = -1e9;
                for(int from = max(0, j - 1); from <= j; ++from) {
                    int inte_val = from, stre_val = (cur - 1) - from;
                    dp[cur][j] = max(dp[cur][j], dp[cur - 1][from] + (int)(upper_bound(inte.begin(), inte.end(), inte_val) - inte.begin()) + (int)(upper_bound(stre.begin(), stre.end(), stre_val) - stre.begin())); 
                }
            }
            inte.clear();
            stre.clear();
        } else {
            if(r[i] > 0) {
                inte.push_back(r[i]);
            } else {
                stre.push_back(-r[i]);
            }
        }
    }
    sort(inte.begin(), inte.end());
    sort(stre.begin(), stre.end());
    for(int j = 0; j <= m; ++j) {
        int inte_val = j, stre_val = cur - j;
        int inte_cnt = upper_bound(inte.begin(), inte.end(), inte_val) - inte.begin();
        int stre_cnt = upper_bound(stre.begin(), stre.end(), stre_val) - stre.begin();
        dp[cur][j] += inte_cnt + stre_cnt; 
    }
    inte.clear();
    stre.clear();
    int ans = 0;
    for(int i = 0; i <= m; ++i) {
        ans = max(ans, dp[m][i]);
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

