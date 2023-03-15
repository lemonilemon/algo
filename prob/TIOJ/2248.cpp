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
vector<pair<int, ll> > graph[MAXN];
ll w[MAXN], cnt[MAXN], cost[MAXN];
int n, k;
void dfs(int u, int pa = -1) {
	cnt[u] = w[u] - k;	
	cost[u] = 0;
	for(auto [v, d] : graph[u]) {
		if(v == pa) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		cost[u] += abs(cnt[v]) * d + cost[v];
	}
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i];		
	}
	for(int i = 0; i < n - 1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		graph[u].emplace_back(make_pair(v, d));
		graph[v].emplace_back(make_pair(u, d));
	}
	dfs(1);
	cout << cost[1] << '\n';
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

