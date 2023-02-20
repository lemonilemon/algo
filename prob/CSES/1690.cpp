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
const int MAXN = 20, MOD = 1e9 + 7;
int madd(int a, int b) {
	return (a + b) % MOD;
}
int mmul(int a, int b) {
	return (1ll * a * b) % MOD;
}
int adj[MAXN][MAXN];
int dp[MAXN][1 << MAXN];
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u -= 2, v -= 2;
		if(u == -1) {
			if(v == -1) continue;
			++dp[v][1 << v];	
		}
		else ++adj[u][v];
	}
	for(int j = 0; j < (1 << (n - 2)); ++j) {
		for(int i = 0; i < n - 2; ++i) {
			if(j & (1 << i)) {
				for(int k = 0; k < n - 2; ++k) {
					if((j & (1 << k)) && adj[k][i]) {
						dp[i][j] = madd(dp[i][j], mmul(adj[k][i], dp[k][j ^ (1 << i)]));
					}
				}
			}
		}
	}
	if(n == 2) {
		cout << dp[0][1] << '\n';
		return;
	}
	int ans = 0;
	for(int i = 0; i < n - 2; ++i) {
		ans = madd(ans, mmul(adj[i][n - 2], dp[i][(1 << (n - 2)) - 1]));
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

