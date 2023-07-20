#include <bits/stdc++.h>
using namespace std;
const int MAXH = 1005, MAXW = 1005;
bool color[MAXH][MAXW];
string r[MAXH];
void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    if(k == 1) {
        int totalcnt = 0, satisfied = 0;
        for(int i = 0; i < 2 * h - 1; ++i) {
            for(int j = 0; j < w - 1 + (int)(i & 1); ++j) {
                ++totalcnt;
                char ch;
                cin >> ch;
                satisfied += (ch == 'E');
            }
        }
        if(satisfied * 4 >= 3 * totalcnt) {
            cout << "YES\n";
            for(int i = 0; i < h; ++i) {
                for(int j = 0; j < w; ++j) {
                    cout << 1 << " \n"[j == w - 1];
                }
            }
        } else cout << "NO\n";
        return;
    }
    if(h > w) {
        for(int i = 0; i < 2 * h - 1; ++i) {
            if(i & 1) {
               for(int j = 0; j < w; ++j) {
                   char ch;
                   cin >> ch;
                   color[(i >> 1) + 1][j] = (ch == 'E'? color[i >> 1][j] : !color[i >> 1][j]);
               }
            } else cin >> r[i >> 1]; // len: w - 1
        }
        for(int i = 0; i + 1 < w; ++i) {
            int cnt = 0;
            for(int j = 0; j < h; ++j) {
                if(color[j][i + 1] == color[j][i]) cnt += (r[j][i] == 'E');
                else cnt += (r[j][i] == 'N');
            }
            cerr << cnt << '\n';
            if(2 * cnt < h) {
                for(int j = 0; j < h; ++j) {
                    color[j][i + 1] = !color[j][i + 1];
                }
            }
        }
    } else {
        for(int i = 0; i < 2 * h - 1; ++i) {
            if(i & 1) cin >> r[i >> 1];
            else {
               for(int j = 0; j < w - 1; ++j) {
                   char ch;
                   cin >> ch;
                   color[i >> 1][j + 1] = (ch == 'E'? color[i >> 1][j] : !color[i >> 1][j]);
               }
            }
        }
        for(int i = 0; i + 1 < h; ++i) {
            int cnt = 0;
            for(int j = 0; j < w; ++j) {
                if(color[i + 1][j] == color[i][j]) cnt += (r[i][j] == 'E');
                else cnt += (r[i][j] == 'N');
            }
            if(2 * cnt < w) {
                for(int j = 0; j < w; ++j) {
                    color[i + 1][j] = !color[i + 1][j];
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cout << color[i][j] + 1 << " \n"[j == w - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
