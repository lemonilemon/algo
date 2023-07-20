#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int space = 6;
char mat[MAXN][MAXN];
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(mat[i][0] == '.') mat[i][0] = 'O';
        if(mat[n - 1][i] == '.') mat[n - 1][i] = 'O';
        if(mat[0][i] == '.') mat[0][i] = 'O';
    }
    for(int i = 0; i < n; ++i) {
        int dis = i % (space << 1);
        int ddis = (space << 1) - dis;
        for(int j = 0; j < n; ++j) {
            if(!dis) {
                if(mat[i][j] == '.') mat[i][j] = 'O';
                continue;
            }
            if(mat[i][j] == 'P') {
                if(dis < space) { // up
                    for(int k = i - dis + 1; k < i; ++k) {
                        if(mat[k][j] == '.') mat[k][j] = 'O';
                    }
                } else { // down
                    for(int k = i + 1; k < min(n, i + ddis); ++k) {
                        if(mat[k][j] == '.') mat[k][j] = 'O';
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << mat[i][j];
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
