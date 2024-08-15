#include <iostream>
using namespace std;
using ll = long long;
const int MAXN = 2005, MAXM = 2005;
int mat[MAXN][MAXM];
bool light[MAXN][MAXM];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            mat[i][j] = (ch == '#');
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!mat[i][j] && !light[i][j]) {

                for(int k = i; k < n; ++k) {
                    if(mat[k][j]) break;
                    light[k][j] = true;
                }

                for(int k = j; k < m; ++k) {
                    if(mat[i][k]) break;
                    light[i][k] = true;
                }
                mat[i][j] = 2;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(mat[i][j] == 0) {
                cout << '.';
            } else if(mat[i][j] == 1) {
                cout << '#';
            } else {
                cout << 'L';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(); 
}

