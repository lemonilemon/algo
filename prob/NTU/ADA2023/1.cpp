#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    ll cur = 0;
    ll mx = -INF;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cur += a;
        mx = max(mx, cur);
        cur = max(cur, 0ll);
    }
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
