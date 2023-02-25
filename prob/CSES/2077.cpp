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
vector<int> graph[MAXN];
int color[MAXN], t[MAXN], low[MAXN], timer;
bool iscut[MAXN];
void dfs(int u = 1, int pa = -1) {
	color[u] = 1;
	t[u] = low[u] = ++timer;
	int chdcnt = 0;
	for(auto v : graph[u]) {
		if(v == pa) continue;
		if(color[v]) low[u] = min(low[u], t[v]);	
		else {
			++chdcnt;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(~pa && low[v] >= t[u]) iscut[u] = 1;
		}
	}
	color[u] = 2;
	if(pa == -1 && chdcnt >= 2) iscut[u] = 1;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	dfs();
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(iscut[i]) ++cnt;
	}
	cout << cnt << '\n';
	for(int i = 1; i <= n; ++i) {
		if(iscut[i]) {
			--cnt;
			cout << i << " \n"[!cnt];
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

