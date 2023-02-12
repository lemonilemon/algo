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

const int MAXN = 2e5 + 5;
ll BIT[MAXN];
void modify(int k, ll val) {
	for(; k < MAXN; k += k & -k) BIT[k] = max(val, BIT[k]);
}
ll query(int k) {
	ll ret = 0;
	for(; k > 0; k -= k & -k) ret = max(BIT[k], ret);
	return ret;
}
int h[MAXN], a[MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> h[i];
	}
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 1; i <= N; ++i) {
		ll dp = 0;
		dp = query(h[i]) + a[i];
		modify(h[i], dp);
		ans = max(ans, dp);
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

