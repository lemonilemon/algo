#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll acc(int b, int k) {
    if(k == 0) return 0;
    if(b == 0) return 0;
    if(b == 5) return 5;
    if(b == 2) {
        int cycle = k / 4, left = k % 4; 
        int cnt = 20 * cycle;
        if(left >= 1) cnt += 2;
        if(left >= 2) cnt += 4;
        if(left >= 3) cnt += 8;
        return cnt;
    }
    return acc((b << 1) % 10, k - 1) + b;
}
int s, k;
ll f(int x) {
   return 1ll * (s + acc(s % 10, x)) * (k - x);
}
void solve() {
    cin >> s >> k;
    int l = 0, r = k + 1;
    while(r - l > 2) {
        int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    ll mx = 0;
    for(int i = l; i < r; ++i) {
        mx = max(mx, f(i));
    }
    cout << mx << '\n';
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
