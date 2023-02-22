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
int sz[MAXN], c[MAXN], chd[MAXN];
void dfs1(int u = 1, int pa = -1) {
	sz[u] = 1;
	chd[u] = -1;
	for(auto v : graph[u]) {
		if(v == pa) continue; 
		dfs1(v, u);
		sz[u] += sz[v];
		if(~chd[u]) {
			if(sz[v] > sz[chd[u]]) chd[u] = v;
		} else chd[u] = v;
	}
}
int ans[MAXN];
set<int> s;
void dfs2(int u = 1, int pa = -1) {
	if(chd[u] == -1) {
		ans[u] = 1;
		return;
	}
	for(auto v : graph[u]) {
		if(v == pa || v == chd[u]) continue;
		dfs2(v, u);
		
	}
	dfs2(chd[u], u);
}
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
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

