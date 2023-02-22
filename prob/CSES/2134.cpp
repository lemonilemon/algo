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
int seg[MAXN << 2];
void pull(int v) {
	seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
void modify(int q, int val, int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int query(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return max(query(ql, mid, l, mid, v << 1), query(mid + 1, qr, mid + 1, r, v << 1 | 1));
}
int sz[MAXN], d[MAXN], p[MAXN], heavy[MAXN], val[MAXN], top[MAXN], id[MAXN];
void dfs(int u = 1, int pa = -1) {
	if(~pa) d[u] = d[pa] + 1;
	else d[u] = 0;
	p[u] = pa;
	heavy[u] = -1;
	sz[u] = 1;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if(~heavy[u]) {
			if(sz[v] > sz[heavy[u]]) heavy[u] = v;
		} else heavy[u] = v;
	}
}
int timer;
void hld(int u = 1, int tp = 1) {
	id[u] = ++timer;	
	modify(id[u], val[u]);
	top[u] = tp;
	if(heavy[u] == -1) return;
	hld(heavy[u], tp);
	for(auto v : graph[u]) {
		if(v == p[u] || v == heavy[u]) continue;
		hld(v, v);	
	}
}
int pathquery(int u, int v) {
	int ret = 0;
	int tu = top[u], tv = top[v];
	while(tu != tv) {
		while(d[tu] < d[tv]) {
			swap(u, v);
			swap(tu, tv);
		}
		ret = max(ret, query(id[tu], id[u]));
		u = p[tu];
		tu = top[u];
	}
	if(d[u] < d[v]) swap(u, v);
	ret = max(ret, query(id[v], id[u]));
	return ret;
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
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
			modify(id[s], x);
		} else {
			int u, v;
			cin >> u >> v;
			cout << pathquery(u, v) << ' ';
		}
	}
	cout << '\n';
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

