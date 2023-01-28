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
int N, K, D;
int mabs(ll a) {
	return (a % D + D) % D;
}
ll madd(int a, int b) {
	return mabs(a + b);
}
const int MAXN = 105, MAXK = 105, MAXD = 105;
ll dp[MAXK][MAXD];
void solve() {
	cin >> N >> K >> D;
	for(int i = 0; i <= K; ++i) {
		for(int j = 0; j < D; ++j) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		for(int j = K; j >= 1; --j) {
			for(int k = 0; k < D; ++k) {
				if(dp[j - 1][madd(k, -a)] == -1) continue;
				dp[j][k] = max(dp[j][k], dp[j - 1][madd(k, -a)] + a);
			}
		}
	}
	cout << dp[K][0] << '\n';
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

