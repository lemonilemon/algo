#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 2e5 + 5;
ll a[MAXN];
void solve() {
    ll l, n;
    cin >> l >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i]; 
    }
    sort(a, a + n);
    ll last = 0; // last not lighted
    ll cnt = 0;
    for(int i = 0; i < n; ++i) {
        ll cur = a[i];
        cnt += (cur - last - 1) / 15;
        last = cur;
    }
    cnt += (l - last) / 15;
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
