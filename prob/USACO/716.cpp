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
FILE* setIO(string file = "countcross") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 105; 
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
set<int> graph[MAXN * MAXN];
int color[MAXN * MAXN];
vector<int> cows;
int N, K, R;
int ordtonum(int x, int y) {
	return (N + 1) * x + y;
}
void dfs(int u) {
	color[u] = 1;
	for(auto v : graph[u]) {
		if(color[v]) continue;
		dfs(v);
	}
	color[u] = 2;
}
void solve() {
	cin >> N >> K >> R;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			int u = ordtonum(i, j);
			debug(u);
			for(int d = 0; d < 4; ++d) {
				int vx = dx[d] + i, vy = dy[d] + j;
				if(vx < 1 || vx > N || vy < 1 || vy > N) continue;
				int v = ordtonum(vx, vy);
				debug(v);
				graph[u].insert(v);
			}
		}
	}
	for(int i = 0; i < R; ++i) {
		int ur, uc, vr, vc;
		cin >> ur >> uc >> vr >> vc;
		int u = ordtonum(ur, uc), v = ordtonum(vr, vc);	
		graph[u].erase(v);
		graph[v].erase(u);
	}
	for(int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		int u = ordtonum(x, y);
		cows.push_back(u);
	}
	int cnt = K * K;
	for(auto u : cows) {
		for(int i = 0; i < (N + 1) * (N + 1); ++i) {
			color[i] = 0;
		}
		dfs(u);
		for(auto v : cows) {
			if(color[v]) --cnt;	
		}
		debug(cnt);
	}
	cnt >>= 1;
	cout << cnt << '\n';
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

