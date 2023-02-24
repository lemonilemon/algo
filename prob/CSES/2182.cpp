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
const int MOD = 1e9 + 7;
int mabs(ll a, int mod = MOD) {
	return (a % mod + mod) % mod;
}
int madd(int a, int b, int mod = MOD) {
	return mabs(a + b, mod);
}
int mmul(int a, int b, int mod = MOD) {
	return mabs(1ll * a * b, mod);
}
int fastpow(int a, int b, int mod = MOD) {
	a = mabs(a, mod);
	int ret = 1;
	while(b) {
		if(b & 1) ret = mmul(ret, a, mod);
		a = mmul(a, a, mod);
		b >>= 1;
	}
	return ret;
}
int inv(ll a, int mod = MOD) {
	a = mabs(a);
	return fastpow(a, mod - 2);
}
void solve() {
	int n;
	cin >> n;
	int ans[3]{};
	int val = 1;
	int cnt = 1;
	ans[0] = ans[1] = 1;
	int sqt = 1;
	bool flag = 1;
	for(int i = 0; i < n; ++i) {
		int x, k;
		cin >> x >> k;
		ans[0] = mmul(ans[0], k + 1);
		ans[1] = mmul(ans[1], mmul(fastpow(x, k + 1) - 1, inv(x - 1)));
		cnt = mmul(cnt, mmul(fastpow(x, k + 1, MOD - 1) - 1, inv(x - 1, MOD - 1)), MOD - 1);
		if(k & 1) flag = 0;
		sqt = mmul(sqt, fastpow(x, k >> 1));
		val = mmul(val, fastpow(x, k));
	}
	ans[2] = fastpow(val, mmul(cnt, inv(2, MOD - 1), MOD - 1));
	if(flag) ans[2] = mmul(ans[2], sqt);
	for(int i = 0; i < 3; ++i) {
		cout << ans[i] << " \n"[i == 2];
	}
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

