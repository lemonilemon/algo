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
const int MAXN = 2e5 + 5;
int dp[MAXN][2];
vector<int> graph[MAXN];
void dfs(int u = 1, int pa = -1) {
	dp[u][0] = dp[u][1] = 0;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dp[u][1] = max(dp[u][1], dp[u][0] + dp[v][0] - max(dp[v][0], dp[v][1]) + 1);
	}	
	debug(u), debug(dp[u][0]), debug(dp[u][1]);
	return;
}
void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs();
	cout << max(dp[1][0], dp[1][1]) << '\n';
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

