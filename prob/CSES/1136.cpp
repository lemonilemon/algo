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
vector<int> graph[MAXN];
int sz[MAXN], heavy[MAXN], id[MAXN], top[MAXN], d[MAXN], p[MAXN], timer;
void dfs(int u, int pa = -1) {
	sz[u] = 1;
	heavy[u] = -1;
	p[u] = pa;
	if(~pa) d[u] = d[pa] + 1;
	else d[u] = 0;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if(~heavy[u]) {
			if(sz[v] > sz[heavy[u]]) heavy[u] = v;
		} else heavy[u] = v;
	}
}
void hld(int u, int tp) {
	id[u] = ++timer;	
	top[u] = tp;
	if(heavy[u] == -1) return;
	hld(heavy[u], tp);
	for(auto v : graph[u]) {
		if(v == p[u] || v == heavy[u]) continue;
		hld(v, v);
	}
}
int BIT[MAXN];
void modify(int k, int val) {
	for(; k < MAXN; k += k & -k) BIT[k] += val;
}
ll query(int k) {
	ll ret = 0;
	for(; k > 0; k -= k & -k) ret += BIT[k];
	return ret;
}
void process(int u, int v) {
	int tu = top[u], tv = top[v];
	while(tu != tv) {
		if(d[tu] < d[tv]) {
			swap(tu, tv);	
			swap(u, v);
		}
		debug(tu), debug(u);
		debug(id[tu]), debug(id[u]);
		modify(id[tu], 1);
		modify(id[u] + 1, -1);
		u = p[tu];
		tu = top[u];
	}
	if(d[u] < d[v]) swap(u, v);
	debug(v), debug(u);
	debug(id[v]), debug(id[u]);
	modify(id[v], 1);
	modify(id[u] + 1, -1);
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	dfs(1);
	hld(1, 1);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		process(u, v);
	}
	for(int i = 1; i <= n; ++i) {
		cout << query(id[i]) << '\n';
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

