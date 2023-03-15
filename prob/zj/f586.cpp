#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 1e6 + 5; 
bool isprime[MAXN];
int mu[MAXN], phi[MAXN];
vector<int> primes;
void sieve() {
	for(int i = 2; i < MAXN; ++i) {
		isprime[i] = 1;
	}
	isprime[1] = 0;
	mu[1] = phi[1] = 1;
	for(int i = 2; i < MAXN; ++i) {
		if(isprime[i]) {
			phi[i] = i - 1;
			mu[i] = -1;
			primes.emplace_back(i);
		}
		for(auto p : primes) {
			if(1ll * i * p >= MAXN) break;
			isprime[i * p] = 0;
			phi[i * p] = phi[i] * phi[p];
			mu[i * p] = mu[i] * mu[p];
			if(!(i % p)) {
				phi[i * p] = phi[i] * p;
				mu[i * p] = 0;
				break;
			}
		}
	}
}
void solve() {
	int N;
	cin >> N;
	cout << mu[N] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		solve();
	}
}

