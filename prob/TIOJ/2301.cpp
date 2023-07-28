#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXA = 1e6 + 5;
int diff[MAXA];
void solve() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++diff[l];
        --diff[r];
    }
    ll cur = 0, cnt = 0;
    for(int i = 1; i < MAXA; ++i) {
        cur += diff[i];
        cnt += (cur * (cur - 1)) >> 1;
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
