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
const int MAXN = 1e5 + 5, MAXM = 11, INF = 1e9 + 7;
int dp[MAXN], rdp[MAXN];
bool adj[MAXN][MAXM];
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			char ch;
			cin >> ch;
			adj[i][j] = ch == '1';
		}
	}
	dp[1] = 0;
	for(int i = 2; i <= N; ++i) {
		dp[i] = INF;
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(adj[i][j]) dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	rdp[N] = 0;
	for(int i = 1; i < N; ++i) {
		rdp[i] = INF;
	}
	for(int i = N; i >= 1; --i) {
		for(int j = 1; j <= M && i - j >= 1; ++j) {
			if(adj[i - j][j]) rdp[i - j] = min(rdp[i - j], rdp[i] + 1);
		}
	}
	for(int i = 2; i < N; ++i) {
		int ans = INF;
		for(int j = max(i - M + 1, 1); j < i; ++j) {
			for(int k = 1; k <= M; ++k) {
				if(j + k <= i) continue;
				if(adj[j][k]) ans = min(ans, dp[j] + rdp[j + k] + 1);
			}
		}
		if(ans == INF) cout << "-1";
		else cout << ans;
		cout << " \n"[i == N - 1];
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

