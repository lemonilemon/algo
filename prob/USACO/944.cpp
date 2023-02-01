#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
FILE* setIO(string file = "fenceplan") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 1e5 + 5, INF = 1e9 + 7;
int x[MAXN], y[MAXN];
vector<int> graph[MAXN];
int color[MAXN];
int mxx, mxy, mnx, mny;
void dfs(int u) {
	mxx = max(mxx, x[u]);
	mxy = max(mxy, y[u]);
	mnx = min(mnx, x[u]);
	mny = min(mny, y[u]);
	color[u] = 1;
	for(auto v : graph[u]) {
		if(color[v]) continue;
		dfs(v);
	}
	color[u] = 2;
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		cin >> x[i] >> y[i];	
	}
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int mn = INF;
	for(int i = 1; i <= N; ++i) {
		if(!color[i]) {
			mxx = 0, mxy = 0, mnx = INF, mny = INF;
			dfs(i);
			debug(mxx), debug(mxy), debug(mnx), debug(mny);
			mn = min(mn, (mxx - mnx + mxy - mny) << 1);
		}
	}
	cout << mn << '\n';
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

