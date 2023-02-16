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
const int MAXN = 3e5 + 5, MOD = 998244353;
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
int modinv(int a) {
	return fastpow(a, MOD - 2);
}
int fac[MAXN];
int comb(int n, int m) {
	return mmul(fac[n], mmul(modinv(fac[m]), modinv(fac[n - m])));
}
void init() {
	fac[0] = 1;	
	for(int i = 1; i < MAXN; ++i) {
		fac[i] = mmul(fac[i - 1], i);
	}
}
void solve() {
	int N;
	cin >> N;
	int ans = 1;
	for(int i = 1; i <= N / 3; ++i) {
		int mul = 1;
		int edge[3];
		int mx = 0;
		for(int j = 0; j < 3; ++j) {
			cin >> edge[j];
			mx = max(edge[j], mx);
		}
		if(edge[0] == edge[1] && edge[1] == edge[2]) {
			mul = mmul(mul, 3);
		} else {
			if(edge[0] == edge[1]) {
				if(edge[0] != mx) mul = mmul(mul, 2);
			} else if(edge[1] == edge[2]) {
				if(edge[1] != mx) mul = mmul(mul, 2);
			} else if(edge[0] == edge[2]) {
				if(edge[0] != mx) mul = mmul(mul, 2);
			}
		}
		ans = mmul(mul, ans);
	}
	ans = mmul(ans, comb(N / 3, N / 6));
	cout << ans << '\n';
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	init();
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

