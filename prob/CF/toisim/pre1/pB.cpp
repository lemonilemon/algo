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
const int MAXN = 2e5 + 5, MOD = 998244353;
int p[MAXN], q[MAXN], tq[MAXN];
int fac[MAXN];
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
int C(int n, int m) {
	return fac[n] * modinv(mmul(fac[m], fac[n - m]));	
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
	for(int i = 1; i <= N; ++i) {
		cin >> p[i];
	}
	int x;
	cin >> x;
	for(int i = 1; i <= N; ++i) {
		cin >> q[i];
		tq[q[i]] = i;
	}
	int y;
	cin >> y;
	set<int> s;
	for(int i = 1; i <= x - 1; ++i) {
		s.insert(tq[p[i]]);	
	}
	int ans = 0;
	int yidx = N, k = s.size();
	for(int i = x; i <= N; ++i) {
		s.insert(tq[p[i]]);	
		if(yidx >= tq[p[i]]) ++k;
		while(yidx >= y && i + yidx - x - y > k) {
			if(s.count(yidx)) --k;
			--yidx;	
		}
		while(yidx > y && i + yidx - x - y == k && s.count(yidx)) {
			--k;
			--yidx;
		}
		if(yidx < y) break;
		debug(i), debug(yidx);
		ans = madd(ans, C(k, i - x));
	}
	cout << ans << '\n';
}

int main() {
	setIO();
	int T = 1;
	init();
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

