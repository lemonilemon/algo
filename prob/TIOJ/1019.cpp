#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
void safe() {
	std::cerr<<"\033[1;32m"<<__PRETTY_FUNCTION__<<" is safe\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
const int MAXN = 1005;
const ll INF = 1e10 + 7;
ll d[MAXN];
ll dp[MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> d[i];
	}
	dp[1] = 0;
	dp[2] = abs(d[2] - d[1]);
	for(int i = 3; i <= N; ++i) {
		dp[i] = min(dp[i - 2] + abs(d[i - 2] - d[i]), dp[i - 1] + abs(d[i - 1] - d[i]));
	}
	cout << dp[N] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}
