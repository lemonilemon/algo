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
const int MAXN = 500005;
vector<int> graph[MAXN];
int low[MAXN], dfn[MAXN], inscc[MAXN], color[MAXN], timer;
bool instk[MAXN];
vector<int> stk;
vector<vector<int> > sccs;
vector<set<int> > sccgraph;
void dfs(int u) {
	low[u] = dfn[u] = ++timer;
	stk.emplace_back(u);
	instk[u] = 1;
	color[u] = 1;
	for(auto v : graph[u]) {
		if(!color[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] >= dfn[u]) {	
		sccs.emplace_back();
		while(stk.back() != u) {
			sccs.back().emplace_back(stk.back());
			instk[stk.back()] = 0;
			inscc[stk.back()] = (int)sccs.size() - 1;
			stk.pop_back();
		}
		sccs.back().emplace_back(stk.back());
		instk[stk.back()] = 0;
		inscc[stk.back()] = (int)sccs.size() - 1;
		stk.pop_back();
	}
	color[u] = 2;
}
vector<int> indeg;
void build() {
	cout << sccs.size() << '\n';
	sccgraph.resize(sccs.size());
	indeg.resize(sccs.size());
	for(auto cc : sccs) {
		for(auto u : cc) {
			for(auto v : graph[u]) {
				if(inscc[u] == inscc[v]) continue;
				sccgraph[inscc[u]].insert(inscc[v]);
			}
		}
	}
	for(int i = 0; i < (int)sccs.size(); ++i) {
		for(auto v : sccgraph[i]) {
			++indeg[v];
		}
	}
}
void sccbfs() {
	queue<int> que;
	for(int i = 0; i < (int)sccs.size(); ++i) {
		if(!indeg[i]) que.push(i);
	}
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		cout << sccs[u].size();
		for(auto node : sccs[u]) {
			cout << ' ' << node;
		}
		cout << '\n';
		for(auto v : sccgraph[u]) {
			--indeg[v];
			if(!indeg[v]) que.push(v);
		}
	}
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
	}
	for(int i = 0; i < N; ++i) {
		if(!color[i]) dfs(i);
	}
	build();
	sccbfs();
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

