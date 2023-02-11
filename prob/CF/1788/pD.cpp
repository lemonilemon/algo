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
const int MAXN = 3005, MOD = 1e9 + 7;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
int x[MAXN], pow2[MAXN];
void init() {
	pow2[0] = 1;
	for(int i = 1; i < MAXN; ++i) {
		pow2[i] = mmul(pow2[i - 1], 2);
	}
}
void solve() {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	ll ans = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = i + 1; j < N; ++j) {
			ll cnt = N - (lower_bound(x, x + N, 2 * x[j] - x[i]) - lower_bound(x, x + N, 2 * x[i] - x[j]));
			debug(i), debug(j), debug(cnt);
			ans = madd(ans, pow2[cnt]);
		}
	}
	cout << ans << '\n';
}

int main() {
	setIO();
	init();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}
