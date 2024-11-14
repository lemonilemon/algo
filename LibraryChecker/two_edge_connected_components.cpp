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
vector<int> graph[MAXN], stk;
int color[MAXN], t[MAXN], low[MAXN], timer; 
int bcccnt;
vector<int> bcc[MAXN];
void dfs(int u, int pa = -1) {
	color[u] = 1;
	stk.push_back(u);
	low[u] = t[u] = ++timer;
	bool flag = 1;
	for(auto v : graph[u]) {
		if(v == pa && flag) {
			flag = 0;
			continue;
		}
		if(color[v]) low[u] = min(t[v], low[u]);
		else {
			dfs(v, u);
			low[u] = min(low[v], low[u]);
		}
	}
	color[u] = 2;
	if(low[u] >= t[u]) {
		++bcccnt;
		while(stk.back() != u) {
			bcc[bcccnt].push_back(stk.back());
			stk.pop_back();
		}
		bcc[bcccnt].push_back(stk.back());
		stk.pop_back();
	}
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		++u, ++v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= N; ++i) {
		if(!color[i]) dfs(i);
	}
	cout << bcccnt << '\n';
	for(int i = 1; i <= bcccnt; ++i) {
		cout << bcc[i].size();
		for(auto u : bcc[i]) {
			cout << ' ' << u - 1;
		}
		cout << '\n';
	}
	return;
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

