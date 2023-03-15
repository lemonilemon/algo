#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 2005, MOD = 1e9 + 7;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int comb[MAXN][MAXN];
void getcomb() {
	for(int i = 0; i < MAXN; ++i) {
		comb[i][0] = 1;
	}
	for(int i = 1; i < MAXN; ++i) {
		for(int j = 1; j <= i; ++j) {
			comb[i][j] = madd(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}
}

int main() {
	getcomb();
	int n, m;
	cin >> n >> m;
	cout << comb[n][m] << '\n';
}

