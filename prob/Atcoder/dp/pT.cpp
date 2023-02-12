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
int dp[2][MAXN];
void solve() {
	int N;
	cin >> N;
	string s;
	cin >> s;	
	dp[1][1] = 1;
	for(int i = 2; i <= N; ++i) {
		if(s[i - 2] == '>') {
			for(int j = i; j >= 1; --j) {
				dp[i & 1][j] = madd(dp[i & 1][j + 1], dp[!(i & 1)][j]);
			}
		} else {
			for(int j = 1; j <= i; ++j) {
				dp[i & 1][j] = madd(dp[i & 1][j - 1], dp[!(i & 1)][j - 1]);
			}
		}
		for(int j = 1; j <= i; ++j) {
			debug(i), debug(j), debug(dp[i & 1][j]);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= N; ++i) {
		ans = madd(ans, dp[N & 1][i]);
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

