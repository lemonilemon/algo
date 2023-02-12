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
const int MAXK = 1e5 + 5, MOD = 1e9 + 7;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int msub(int a, int b) {
	return mabs(a - b);
}
ll dp[2][MAXK];
ll presum[MAXK];
void solve() {
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	for(int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		presum[0] = dp[!(i & 1)][0];
		for(int j = 1; j <= K; ++j) {
			presum[j] = madd(presum[j - 1], dp[!(i & 1)][j]);
		}
		for(int j = 0; j <= K; ++j) {
			if(j - a - 1 >= 0) dp[i & 1][j] = msub(presum[j], presum[j - a - 1]);
			else dp[i & 1][j] = presum[j];
		}
	}
	cout << dp[N & 1][K] << '\n';
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

