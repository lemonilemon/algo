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
const int MAXN = 1e5 + 5;
vector<int> graph[MAXN], rgraph[MAXN];
int color[MAXN];
void dfs(int u) {
	color[u] = 1;
	for(auto v : graph[u]) {
		if(!color[v]) dfs(v);
	}
	color[u] = 2;
}
void rdfs(int u) {
	color[u] = 1;
	for(auto v : rgraph[u]) {
		if(!color[v]) rdfs(v);
	}
	color[u] = 2;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		debug(i), debug(color[i]);
		if(!color[i]) {
			cout << "NO\n";
			cout << 1 << ' ' << i << '\n';
			return;
		} 
		color[i] = 0;
	}
	rdfs(1);
	for(int i = 1; i <= n; ++i) {
		debug(i), debug(color[i]);
		if(!color[i]) {
			cout << "NO\n";
			cout << i << ' ' << 1 << '\n';
			return;
		} 
		color[i] = 0;
	}
	cout << "YES\n";
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

