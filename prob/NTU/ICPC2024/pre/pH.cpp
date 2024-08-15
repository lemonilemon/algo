#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 5, MAXM = 1e6 + 5;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
int mabs(ll a) {
    return a % MOD;
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
        b >>= 1;
        a = mmul(a, a);
    }
    return ret;
}
int inv(int a) {
    return fastpow(a, MOD - 2);
}
int fact[MAXN + MAXM];
void solve() {
    int n, m;
    cin >> n >> m;
    fact[0] = 1;
    for(int i = 1; i <= n + m; ++i) {
        fact[i] = mmul(fact[i - 1], i);
    }
    const int c = mmul(mmul(fact[n + 1], fact[m - 1]), mmul(mmul(fact[m], fact[n]), inv(fact[n + m])));
    for(int k = 1; k <= m; ++k) {
        int n_left = n - (k - 1);
        if(n_left < 0) {
            cout << 0 << " \n"[k == m];
            continue;
        }
        int denom = mmul(mmul(fact[n - k + 1], fact[k]), mmul(fact[m - k], fact[k - 1]));
        // cout << mmul(mmul(cnt1, cnt2), inv(fact[n + m])) << " \n"[k == m];
        cout << mmul(inv(denom), c) << " \n"[k == m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(); 
}

