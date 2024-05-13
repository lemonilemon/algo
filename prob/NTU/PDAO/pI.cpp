#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    int cnt = 1;
    ll curmx;
    cin >> curmx;
    vector<ll> presum;
    presum.push_back(0);
    for(int i = 1; i < n; ++i) {
        ll a;
        cin >> a;
        presum.push_back(presum.back() + a);
        if(presum.back() >= curmx) {
            int l = 0, r = presum.size();
            while(r - l > 1) {
                int mid = (l + r) >> 1;
                if(presum.back() - curmx >= 2 * presum[mid]) l = mid;
                else r = mid; 
            }
            ++cnt;
            curmx = presum.back() - presum[l];
            presum.clear();
            presum.push_back(0);
        }
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
