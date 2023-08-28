#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 998244353;
const int MAXN = 1e6 + 7;
int premul[MAXN];
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
int fastpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = mmul(ret, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ret;
}
void solve() {
    int N;
    cin >> N;
    premul[1] = 1;
    for(int i = 2; i <= N; ++i) {
        premul[i] = mmul(premul[i - 1], i);
    }
    for(int i = 1; i < N; ++i) {
        cout << mmul(i, fastpow(premul[i + 1], MOD - 2)) << ' ';
    }
    cout << "0\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
