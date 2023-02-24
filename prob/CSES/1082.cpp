#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int MOD = 1e9 + 7;

int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(ll a, ll b) {
	a %= MOD;
	b %= MOD;
	return mabs(a + b);
}
int mmul(ll a, ll b) {
	a %= MOD;
	b %= MOD;
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
int inv2 = fastpow(2, MOD - 2);
void solve() {
	ll n;
	cin >> n;
	int ans = 0;
	for(ll i = 1; i <= n; ++i) {
		ll nexti = n / (n / i);
		int len = mabs(nexti - i + 1);
		int val = mmul(n/i, mmul(mmul(madd(nexti, i), len), inv2));
		ans = madd(ans, val);
		debug(i);
		debug(nexti);
		debug(ans);
		i = nexti;
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

