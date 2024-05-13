#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXM = 1e6 + 5;
ll f[MAXM];
ll m, k;
bool check(ll x) {
    vector<ll> vals;
    for(int i = 1; i <= x; ++i) {
        vals.push_back(f[i] - k);
    } 
    sort(vals.begin(), vals.end());
    for(int i = 1; i < (int)vals.size(); ++i) {
        if(vals[i] <= 0) return 0;
        ll dif = k - vals[i];
        if(dif > 0) {
            if(i < x - 1) vals[i + 1] -= dif; 
        }
    }
    return 1;
}
void solve() {
    cin >> m >> k;
    for(int i = 1; i <= m; ++i) {
        cin >> f[i];
    }
    ll l = 1, r = m + 1;
    while(r - l > 1) {
        ll mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; 
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
    return 0;
}

