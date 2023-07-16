#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long int n, p, q;
    cin >> n >> p >> q;
    int mnd = 1e9 + 7;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        mnd = min(mnd, d);
    }
    cout << min(q + mnd, p) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
