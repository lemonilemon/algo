#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, MAXK = 2e5 + 5;
int dp[MAXN][2], laststep[MAXK];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        laststep[i] = 0;
    }
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        int last = laststep[c]; 
        dp[i][0] = dp[last][0]; // max
        dp[i][1] = dp[last][1]; // smax
        int val = i - last - 1;
        if(val > dp[i][0]) {
            dp[i][1] = dp[i][0];
            dp[i][0] = val;
        } else if(val >= dp[i][1]) dp[i][1] = val; 
        laststep[c] = i;
        // cerr << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    int mn = n;
    for(int i = 1; i <= k; ++i) {
        int last = laststep[i];
        int mx = dp[last][0], smx = dp[last][1];
        int val = n - last;
        if(val > mx) {
            smx = mx;
            mx = val;
        } else if(val > smx) smx = val; 
        // cerr << i << ' ' << last << ' ' << mx << ' ' << smx << '\n';
        mn = min(max(mx >> 1, smx), mn);
    }
    cout << mn << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
