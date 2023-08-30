#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    int mx = a, mn = a;
    int cur = a;
    for(int i = 0; i < q; ++i) {
        char ch;
        cin >> ch;
        if(ch == '+') {
            ++mx;
            ++cur;
            mn = max(mn, cur);
        } else --cur;
    }
    if(mx >= n) {
        if(mn >= n) cout << "YES\n";
        else cout << "MAYBE\n";
    } else {
        cout << "NO\n";
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
