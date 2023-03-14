#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
#define safe() std::cerr << "\033[1;32m" << __PRETTY_FUNCTION__ << " is safe\033[0m\n"
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
FILE* setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MOD = 1e9 + 9, INV2 = 5e8 + 5;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(ll a, ll b) {
	a = a % MOD, b = b % MOD;
	return mabs(a + b);
}
int mmin(ll a, ll b) {
	a = a % MOD, b = b % MOD;
	return mabs(a - b);
}
int mmul(ll a, ll b) {
	a = a % MOD, b = b % MOD;
	return mabs(a * b);
}
void solve() {
	ll N;
	cin >> N;
	int ans = mmul(N, N);
	for(ll i = 1; i <= N; ++i) {
		ll nxti = N / (N / i);
		ll len = nxti - i + 1;
		ans = mmin(ans, mmul(mmul(mmul(i + nxti, len), INV2), N / i));
		i = nxti;
	}
	cout << ans << '\n';
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

