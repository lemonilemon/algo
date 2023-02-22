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
int id[MAXN], sz[MAXN], v[MAXN], chd[MAXN], d[MAXN], p[MAXN], top[MAXN];
ll BIT[MAXN];
void modify(int k, int val) {
	for(; k < MAXN; k += k & -k) BIT[k] += val;
}
ll query(int k) {
	ll ret = 0;
	for(; k > 0; k -= k & -k) ret += BIT[k];
	return ret;
}
void dfs(int u = 1, int pa = -1) {
	if(~pa) d[u] = d[pa] + 1;
	else d[u] = 0;
	p[u] = pa;
	chd[u] = -1;
	sz[u] = 1;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		if(~chd[u]) {
			if(sz[v] > sz[chd[u]]) chd[u] = v;
		} else chd[u] = v;
		sz[u] += sz[v];
	}
}
int timer;
void hld(int u = 1, int tp = 1) {
	id[u] = ++timer;
	modify(id[u], v[u]);
	top[u] = tp;	
	if(chd[u] == -1) return;
	hld(chd[u], tp);
	for(auto v : graph[u]) {
		if(v == p[u] || v == chd[u]) continue;
		hld(v, v);
	}
}
ll pathquery(int u, int v) {
	int tu = top[u], tv = top[v];
	ll ret = 0;
	while(tu != tv) {
		if(d[tu] < d[tv]) {
			swap(u, v);
			swap(tu, tv);
		}
		ret += query(id[u]) - query(id[tu] - 1);	
		u = p[tu];
		tu = top[u];
	}
	if(d[u] < d[v]) swap(u, v);
	ret += query(id[u]) - query(id[v] - 1);
	return ret;
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	dfs();
	hld();
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int s, x;
			cin >> s >> x;
			modify(id[s], x - (query(id[s]) - query(id[s] - 1)));
		} else {
			int s;
			cin >> s;
			cout << pathquery(1, s) << '\n';
		}
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

