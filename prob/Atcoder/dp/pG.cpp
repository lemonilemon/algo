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
int indeg[MAXN], dp[MAXN];
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		++indeg[v];
	}
	queue<int> que;
	for(int i = 1; i <= N; ++i) {
		if(!indeg[i]) que.push(i);
	}
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for(auto v : graph[u]) {
			dp[v] = max(dp[u] + 1, dp[v]);
			if(!(--indeg[v])) que.push(v);
		}
	}
	int mx = 0;
	for(int i = 1; i <= N; ++i) {
		mx = max(mx, dp[i]);
	}
	cout << mx << '\n';
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

