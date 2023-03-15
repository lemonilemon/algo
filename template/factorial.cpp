#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, MOD = 1e9 + 7;
using ll = long long int;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
int fac[MAXN];
void getfac() {
	fac[0] = 1;	
	for(int i = 1; i < MAXN; ++i) {
		fac[i] = mmul(fac[i - 1], i);
	}
}
int main() {
	getfac();
	int n;
	cin >> n;
	cout << fac[n] << '\n';
}
