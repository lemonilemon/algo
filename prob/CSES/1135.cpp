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
int d[MAXN], p[MAXN][__lg(MAXN) + 1];
void dfs(int u = 1, int pa = -1) {
	if(~pa) {
		p[u][0] = pa;
		d[u] = d[pa] + 1;
	} else d[u] = 0;
	for(int i = 1; i <= __lg(d[u]); ++i) {
		p[u][i] = p[p[u][i-1]][i-1];
	}
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
	}
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	int dis = d[u] - d[v];
	while(dis) {
		u = p[u][__lg(dis)];
		dis ^= 1 << __lg(dis);
	}
	if(u == v) return u;
	for(int i = __lg(d[u]); i >= 0; --i) {
		if(p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	dfs();
	for(int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		int k = lca(u, v);
		cout << d[u] + d[v] - 2 * d[k] << '\n';
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

