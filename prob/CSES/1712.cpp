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
int mabs(ll a, int mod) {
	return (a % mod + mod) % mod;
}
int mmul(int a, int b, int mod) {
	return mabs(1ll * a * b, mod);
}
int fastpow(int a, int b, int mod) {
	int ret = 1;	
	while(b) {
		if(b & 1) ret = mmul(ret, a, mod);
		a = mmul(a, a, mod);
		b >>= 1;
	}
	return ret;
}
void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << fastpow(a, fastpow(b, c, MOD - 1), MOD) << '\n';
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

