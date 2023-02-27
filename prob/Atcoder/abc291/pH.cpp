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
vector<int> graph[MAXN];
int sz[MAXN], color[MAXN];
void dfs_sz(int u, int pa = -1) {
	sz[u] = 1;
	for(auto v : graph[u]) {
		if(color[v] || v == pa) continue;
		dfs_sz(v, u);
		sz[u] += sz[v];
	}	
}
int dfs_cen(int u, int tot, int pa = -1) {
	for(auto v : graph[u]) {
		if(color[v] || v == pa) continue;
		if((sz[v] << 1) > tot) return dfs_cen(v, tot, u);
	}
	return u;
}
int par[MAXN];
void cd(int u, int pa = -1) {
	dfs_sz(u);
	int c = dfs_cen(u, sz[u]);
	color[c] = 1;
	par[c] = pa;	
	for(auto v : graph[c]) {
		if(color[v]) continue;
		cd(v, c);
	}
	color[c] = 2;
}
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	cd(1);
	for(int i = 1; i <= N; ++i) {
		cout << par[i] << " \n"[i == N];
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

