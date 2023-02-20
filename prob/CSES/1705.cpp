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
int color[MAXN], t[MAXN], low[MAXN], inbcc[MAXN];
int timer;
bool iscut[MAXN];
vector<int> stk, graph[MAXN], depth;
vector<vector<int> > bcc, bccgraph, par;

void tarjan(int u, int pa = -1) {
	color[u] = 1;
	t[u] = low[u] = ++timer;
	stk.emplace_back(u);
	for(auto v : graph[u]) {
		if(v == pa) continue;
		if(color[v]) low[u] = min(low[u], t[v]);	
		else {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= t[u]) {
				iscut[u] = 1;
				bcc.emplace_back();
				bccgraph.emplace_back();
				//debug(bcc.size());
				//debug(bccgraph.size());
				while(stk.back() != u) {
					bccgraph.back().emplace_back(stk.back());
					bccgraph[stk.back()].emplace_back(bccgraph.size() - 1);
					bcc.back().emplace_back(stk.back());
					inbcc[stk.back()] = bcc.size() - 1;	
					stk.pop_back();
				}
				bccgraph.back().emplace_back(u);
				bccgraph[u].emplace_back(bccgraph.size() - 1);
				bcc.back().emplace_back(u);
				inbcc[u] = -1;	
			}
		}
	}
	color[u] = 2;
	if(pa == -1) stk.pop_back();	
}
void dfs(int u = 0, int pa = -1) {
	if(~pa) {
		par[u].emplace_back(pa);	
		depth[u] = depth[pa] + 1;
	} else depth[u] = 0;
	for(int i = 0; i < (int)par[u].size(); ++i) {
		if((int)par[par[u][i]].size() > i) par[u].emplace_back(par[par[u][i]][i]);	
	}
	for(auto v : bccgraph[u]) {
		if(v == pa) continue;
		dfs(v, u);
	}
}
void findbcc(int n) {
	bccgraph.resize(n);
	for(int i = 0; i < n; ++i) {
		if(!color[i]) tarjan(i);
	}
	par.resize(bccgraph.size());
	depth.resize(bccgraph.size());
	dfs();
	for(int u = 0; u < (int)bccgraph.size(); ++u) {
		for(auto v : bccgraph[u]) {
			cout << u << ' ' << v << '\n';
		}
	}
	/*for(int i = 0; i < (int)bcc.size(); ++i) {
		debug(i);
		for(auto u : bcc[i]) {
			debug(u);
		}
	}*/
	/*for(int i = 0; i < (int)bccgraph.size(); ++i) {
		debug(i);
		for(auto p : par[i]) {
			debug(p);
		}
	}*/
}
int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);		
	int dis = depth[u] - depth[v];
	while(dis) {
		u = par[u][__lg(dis)];
		dis -= 1 << __lg(dis);
	}
	if(u == v) return u;
	for(int i = __lg(depth[u]); i >= 0; --i) {
		if(par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	findbcc(n);
	for(int i = 0; i < q; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v, --c;
		int k = lca(u, v), s1 = lca(u, c), s2 = lca(v, c);
		/*if((s1 == c && lca(k, s1) == k) || (s2 == c && lca(k, s2) == k)) cout << "NO\n";
		else cout << "YES\n";*/
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

