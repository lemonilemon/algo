#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 1005, MAXM = 1005;
const ll INF = 1e18 + 7;
ll a[MAXN], b[MAXM];
ll pre[2][MAXN];
ll dp[MAXN][MAXM];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i) {
        pre[0][i] = pre[0][i - 1] + a[i];
    }
    for(int i = 1; i <= m; ++i) {
        pre[1][i] = pre[1][i - 1] + b[i];
    }
    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i) {
        dp[i][0] = pre[0][i];
        if(pre[0][i] < 0) dp[i][0] = INF;
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    }
    for(int i = 0; i <= m; ++i) {
        dp[0][i] = pre[1][i];
        if(pre[1][i] < 0) dp[0][i] = INF;
        dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            ll val = pre[0][i] + pre[1][j];
            if(val < 0) val = INF;
            dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), val);
        }
    }

    if(dp[n][m] >= INF) cout << "-1\n";
    else cout << dp[n][m] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
