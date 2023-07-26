#include <bits/stdc++.h>
using namespace std;
const int MAXH = 3005, MAXW = 3005;
int dp[MAXH][MAXW];
bool mat[MAXH][MAXW];
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 0; i < n; ++i) {
       int x, y;
       cin >> x >> y;
       mat[x][y] = 1;
    }
    long long int ans = 0;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(mat[i][j]) dp[i][j] = 0;
            else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
