#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 10007;
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
int a, b, c, d;
int f(int x) {
    int val = 0;
    val = madd(val, a);
    val = mmul(val, x);
    val = madd(val, b);
    val = mmul(val, x);
    val = madd(val, c);
    val = mmul(val, x);
    val = madd(val, d);
    return val;
}
void solve() {
    cin >> a >> b >> c >> d;
    vector<int> ans;
    for(int i = 0; i < MOD; ++i) {
        if(!f(i)) ans.emplace_back(i);
    }
    cout << (int)ans.size() << '\n';
    for(auto p : ans) {
        cout << p << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
