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
int s(int n) {
	return __lg(n) + 1;
}
const int MAXN = 1e6 + 5, MOD = 998244353;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
int mx[MAXN], cnt[MAXN];
int precnt[MAXN];
void init() {
	cnt[1] = 1;
	for(int i = 1; i < MAXN; ++i) {
		mx[i] = s(i);
		if(!(i % 2)) cnt[i] = madd(cnt[i], cnt[i >> 1]);
		if(!(i % 3) && mx[i / 3] + 1 == mx[i]) cnt[i] = madd(cnt[i], cnt[i / 3]);
	}
	for(int i = 1; i < MAXN; ++i) {
		precnt[i] = madd(precnt[i - 1], cnt[i]);
	}
}
void solve() {
	int l, r;
	cin >> l >> r;
	int mxarg = r / l;
	int bound = (1 << __lg(mxarg));
	int ans = 0;
	for(int i = l; i <= r && r / i >= bound; ++i) {
		int nxti = r / (r / i);
		ans = madd(ans, mmul(nxti - i + 1, madd(precnt[r / i], precnt[bound - 1])));
		i = nxti;
	}
	cout << s(mxarg) << ' ' << ans << '\n';
}

int main() {
	setIO();
	init();
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

