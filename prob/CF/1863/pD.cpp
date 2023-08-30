#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int lcntcol[MAXN], rcntcol[MAXN], ucntrow[MAXN], dcntrow[MAXN];
char ans[MAXN][MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        ucntrow[i] = dcntrow[i] = 0;
    }
    for(int i = 1; i <= m; ++i) {
        lcntcol[i] = rcntcol[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            if(ch == 'L') {
                ++lcntcol[j];
                if(lcntcol[j] & 1) ans[i][j] = 'W';
                else ans[i][j] = 'B';
            } else if(ch == 'R') {
                ++rcntcol[j];
                if(rcntcol[j] & 1) ans[i][j] = 'B';
                else ans[i][j] = 'W';
            } else if(ch == 'U') {
                ++ucntrow[i];
                if(ucntrow[i] & 1) ans[i][j] = 'W';
                else ans[i][j] = 'B';
            } else if(ch == 'D') {
                ++dcntrow[i];
                if(dcntrow[i] & 1) ans[i][j] = 'B';
                else ans[i][j] = 'W';
            } else ans[i][j] = '.';
        }
    }
    for(int i = 1; i <= n; ++i) {
        if((ucntrow[i] & 1) || (dcntrow[i] & 1)) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 1; i <= m; ++i) {
        if((lcntcol[i] & 1) || (rcntcol[i] & 1)) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
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
