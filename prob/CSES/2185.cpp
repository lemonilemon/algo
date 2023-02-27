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
const int MAXK = 20;
const ll INF = 1e18 + 7;
ll a[MAXK];
ll mul[1 << MAXK];
void solve() {
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	mul[0] = 1;
	ll ans = 0;
	for(int i = 1; i < (1 << k); ++i) {
		if((double)a[__lg(i)] * mul[i ^ (1 << __lg(i))] > n) mul[i] = 0;
		else mul[i] = a[__lg(i)] * mul[i ^ (1 << __lg(i))];
		if(mul[i]) ans += n / mul[i] * ((__builtin_popcount(i) & 1)? 1 : -1);
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

