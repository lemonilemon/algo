#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
int f(int x, int y) {
    if(x == 0) return 0;
    if(y == 0) return 1;
    int cnt = 0; // mod 3
    if(x > y) {
        int minus = x / y; 
        if(minus & 1) return (1 + f(y, x % y)) % 3;
        return f(x % y, y);
    } else {
        int minus = y / x; 
        if(minus & 1) return (2 + f(y % x, x)) % 3;
        return f(x, y % x);
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i]; 
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int color = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0 && b[i] == 0) continue;
        int c = f(a[i], b[i]);
        // cerr << i << ' ' << c << '\n';
        if(color == -1) color = c;
        else if(color != c) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
