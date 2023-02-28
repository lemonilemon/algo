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
const int MAXN = 1e5 + 5;
vector<pair<int, int> > graph[MAXN];
int sz[MAXN], color[MAXN];
void dfs_sz(int u, int pa = -1) {
	sz[u] = 1;
	for(auto [v, w] : graph[u]) {
		if(color[v] || v == pa) continue;
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
	return;
}
int dfs_cen(int u, int tot, int pa = -1) {
	for(auto [v, w] : graph[u]) {
		if(color[v] || v == pa) continue;
		if(sz[v] * 2 > tot) return dfs_cen(v, tot, u);
	}
	return u;
}
vector<int> child[MAXN];
int par[MAXN];
void cd(int u, int pa = -1) {
	if(~pa) child[pa].emplace_back(u);
	par[u] = pa;
	dfs_sz(u);
	int c = dfs_cen(u, sz[u]);
	color[c] = 1;
	for(auto [v, w] : graph[c]) {
		if(color[v] || v == pa) continue;
		cd(v, c);
	}
	color[c] = 2;
}
void solve() {
	int N, Q;
	cin >> N >> Q;
	for(int i = 0; i < N - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(make_pair(v, w));
		graph[v].emplace_back(make_pair(u, w));
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

