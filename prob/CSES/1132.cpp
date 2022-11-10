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
vector<int> graph[MAXN];
int mxd[MAXN], backtrack[MAXN], smxd[MAXN];
int ans[MAXN];
void dfs(int u = 1, int pa = -1) {
	mxd[u] = smxd[u] = 0;
	backtrack[u] = -1;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		if(mxd[v] + 1 > mxd[u]) {
			smxd[u] = mxd[u];
			mxd[u] = mxd[v] + 1;
			backtrack[u] = v;
		} else smxd[u] = max(smxd[u], mxd[v] + 1);	
	}
}
void dfs2(int u = 1, int pa = -1, int mx = -1) {
	if(pa == -1) ans[u] = mxd[u];
	else ans[u] = max(mx, mxd[u]);
	for(auto v : graph[u]) {
		if(v == pa) continue;
		if(v == backtrack[u]) dfs2(v, u, max(smxd[u], mx) + 1);
		else dfs2(v, u, ans[u] + 1);	
	}
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
	dfs2();
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
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

