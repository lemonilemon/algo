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
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;
vector<pair<int, int> > graph[MAXN];
bool used[MAXM];
int indeg[MAXN], outdeg[MAXN], color[MAXN];
vector<int> ans;
void dfs(int u) {
	color[u] = 1;
	for(auto [v, eid] : graph[u]) {
		if(color[v]) continue;
		dfs(v);
	}
	color[u] = 2;
}
void euler(int u) {
	while(!graph[u].empty()) {
		auto [v, eid] = graph[u].back();
		graph[u].pop_back();
		if(used[eid]) continue;
		used[eid] = 1;
		euler(v);
	}
	ans.push_back(u);
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(make_pair(v, i));
		++indeg[v];
		++outdeg[u];
	}
	dfs(1);
	if(!color[n]) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if(outdeg[1] != indeg[1] + 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if(indeg[n] != outdeg[n] + 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int i = 2; i < n; ++i) {
		if(color[i]) {
			if(indeg[i] != outdeg[i]) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		} else if(indeg[i] || outdeg[i]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	euler(1);
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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

