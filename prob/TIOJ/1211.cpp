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
const int MAXN = 10005;
struct DSU {
	int rt[MAXN], rk[MAXN];
	DSU() {
		for(int i = 0; i < MAXN; ++i) {
			rt[i] = i;
			rk[i] = 1;
		}
	}
	void init() {
		for(int i = 0; i < MAXN; ++i) {
			rt[i] = i;
			rk[i] = 1;
		}
	}
	int find(int u) {
		if(u == rt[u]) return u;	
		return rt[u] = find(rt[u]);
	}
	bool setunion(int u, int v) {
		u = find(u), v = find(v);			
		if(u == v) return 0;
		if(rk[u] < rk[v]) swap(u, v);
		rt[v] = u;
		rk[u] += rk[v];
		return 1;
	}
};
void solve() {
	int n, m;
	while(cin >> n >> m) {
		if(!n && !m) break;
		DSU dsu;
		vector<pair<int, pair<int, int> > > edge;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edge.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(edge.begin(), edge.end());
		ll ans = 0;
		for(int i = 0; i < m; ++i) {
			auto [w, e] = edge[i];
			auto [u, v] = e;
			if(dsu.setunion(u, v)) ans += w;
		}
		if(dsu.rk[1] == n) cout << ans << '\n';
		else cout << "-1\n";
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

