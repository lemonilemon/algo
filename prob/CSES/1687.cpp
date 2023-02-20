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
int d[MAXN];
vector<int> child[MAXN], p[MAXN];
void dfs(int u = 1, int pa = -1) {
	if(~pa) {
		p[u].emplace_back(pa);
		d[u] = d[pa] + 1;
	} else d[u] = 0;
	for(int i = 0; i < (int)p[u].size(); ++i) {
		if((int)p[p[u][i]].size() > i) p[u].emplace_back(p[p[u][i]][i]);
	}
	for(auto v : child[u]) {
		dfs(v, u);
	}
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 2; i <= n; ++i) {
		int u;
		cin >> u;
		child[u].emplace_back(i);
	}
	dfs();
	for(int i = 0; i < q; ++i) {
		int u, k;
		cin >> u >> k;
		if(d[u] < k) {
			cout << "-1\n";
			continue;
		}
		while(k) {
			u = p[u][__lg(k)];
			k ^= 1 << __lg(k);
		}
		cout << u << '\n';
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

