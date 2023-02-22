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
int v[MAXN], tl[MAXN], tr[MAXN], timer;
ll BIT[MAXN];
void modify(int k, int val) {
	for(; k < MAXN; k += k & -k) BIT[k] += val;
}
ll query(int k) {
	ll ret = 0;
	for(; k > 0; k -= k & -k) ret += BIT[k];
	return ret;
}
void dfs(int u, int pa = -1) {
	tl[u] = ++timer;
	modify(tl[u], v[u]);
	for(auto v : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
	}
	tr[u] = timer;
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
	dfs(1);
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int s, x;
			cin >> s >> x;
			int ori = query(tl[s]) - query(tl[s] - 1);
			modify(tl[s], -ori + x);
		} else {
			int s;
			cin >> s;
			cout << query(tr[s]) - query(tl[s] - 1) << '\n';
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

