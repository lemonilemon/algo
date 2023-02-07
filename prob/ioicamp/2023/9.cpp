#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int mabs(ll a, int mod) {
	return (a % mod + mod) % mod;
}
int madd(int a, int b, int mod) {
	return mabs(a + b, mod);
}
int mmul(int a, int b, int mod) {
	return mabs(1ll * a * b, mod);
}
int fastpow(int a, int b, int mod) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = mmul(ret, a, mod);
		a = mmul(a, a, mod);
		b >>= 1;
	}
	return ret;
}
void solve() {
	int n, x;
	cin >> n >> x;
	int power = fastpow(2, n, 10006);
	int ans = fastpow(x, power, 10007);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
