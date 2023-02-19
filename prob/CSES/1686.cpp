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
vector<int> graph[MAXN], stk;
int k[MAXN];
int t[MAXN], low[MAXN], color[MAXN], inscc[MAXN], timer;
bool instk[MAXN];
vector<vector<int> > scc, sccgraph;
vector<int> indeg;
vector<ll> val, dp;
void tarjan(int u) {
	color[u] = 1;	
	low[u] = t[u] = ++timer;
	instk[u] = 1;
	stk.emplace_back(u);
	for(auto v : graph[u]) {
		if(!color[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		} else if(instk[v]) low[u] = min(t[v], low[u]);
	}
	color[u] = 2;
	if(t[u] == low[u]) {
		scc.emplace_back();
		while(stk.back() != u) {
			scc.back().emplace_back(stk.back());
			inscc[stk.back()] = scc.size() - 1;
			instk[stk.back()] = 0;
			stk.pop_back();
		}
		scc.back().emplace_back(stk.back());
		inscc[stk.back()] = scc.size() - 1;
		instk[stk.back()] = 0;
		stk.pop_back();
	}
}
void findscc(int n) {
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) tarjan(i);
	}
	sccgraph.resize(scc.size());
	val.resize(scc.size());
	indeg.resize(scc.size());
	dp.resize(scc.size());
	for(int i = 0; i < (int)scc.size(); ++i) {
		debug(i);
		for(auto u : scc[i]) {
			debug(u);
			val[i] += k[u];
		}
		debug(val[i]);
	}
	for(auto cc : scc) {
		for(auto u : cc) {	
			for(auto v : graph[u]) {
				if(inscc[v] == inscc[u]) continue;
				sccgraph[inscc[u]].emplace_back(inscc[v]);
			}
		}
	}
	for(auto& adj : sccgraph) {
		sort(adj.begin(), adj.end());
		adj.erase(unique(adj.begin(), adj.end()), adj.end());
	}
	for(int u = 0; u < (int)scc.size(); ++u) {
		for(auto v : sccgraph[u]) {
			debug(u), debug(v);
			++indeg[v];
		}
	}
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		cin >> k[i];
	}
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
	}
	findscc(N);
	queue<int> que;
	for(int i = 0; i < (int)scc.size(); ++i) {
		if(!indeg[i]) que.push(i);	
	}
	ll ans = 0;
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		dp[u] += val[u];
		ans = max(dp[u], ans);
		for(auto v : sccgraph[u]) {
			--indeg[v];
			dp[v] = max(dp[v], dp[u]);
			if(!indeg[v]) que.push(v);
		}
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

