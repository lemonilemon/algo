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
const int MOD = 998244353, MAXN = 2e5 + 5;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
int pow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = mmul(ret, a);
		a = mmul(a, a);
		b >>= 1;
	}
	return ret;
}
int inv(int a) {
	return pow(a, MOD - 2);
}
int frac(int a, int b) {
	return mmul(a, inv(b));
}
int factor[MAXN];
int comb(int a, int b) {
	return mmul(factor[a], inv(mmul(factor[a - b], factor[b])));
}
void solve() {
	factor[0] = 1;
	for(int i = 1; i < MAXN; ++i) {
		factor[i] = mmul(factor[i - 1], i);
	}
	int N, p;
	cin >> N >> p;
	int p1 = mmul(100 - p, inv(100)), p2 = mmul(p, inv(100));
	int ans = 0;
	// to 0
	for(int k = (N & 1); k <= N; k += 2) {
		int a = (N - k) >> 1;
		debug(a), debug(k);
		int pos = mmul(mmul(pow(p1, k), pow(p2, a)), comb(a + k, a));
		debug(mmul(pos, 1000000));
		ans = madd(mmul(pos, a + k), ans);
	}
	// to -1
	for(int k = !(N & 1); k <= N; k += 2) {
		int a = (N - k) >> 1;
		debug(a), debug(k);
		int pos = mmul(mmul(pow(p1, k), pow(p2, a + 1)), comb(a + k, a));
		ans = madd(mmul(pos, a + k + 1), ans);
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

