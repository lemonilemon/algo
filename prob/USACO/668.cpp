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
FILE* setIO(string file = "moocast") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 205;
tuple<int, int, int> cow[MAXN];
vector<int> graph[MAXN];
int color[MAXN];
void dfs(int u) {
	color[u] = 1;
	for(auto v : graph[u]) {
		if(color[v]) continue;
		dfs(v);
	}
	color[u] = 2;
}
ll sqr(int a) {
	return 1ll * a * a;
}
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		auto& [x, y, p] = cow[i];
		cin >> x >> y >> p;
	}
	for(int i = 1; i <= N; ++i) {
		auto [xi, yi, pi] = cow[i];
		for(int j = i + 1; j <= N; ++j) {
			auto [xj, yj, pj] = cow[j];	
			ll d2 = sqr(xj - xi) + sqr(yj - yi);
			if(d2 <= sqr(pi)) graph[i].push_back(j);
			if(d2 <= sqr(pj)) graph[j].push_back(i);	
		}
	}
	int mxcnt = 0;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			color[j] = 0;
		}
		dfs(i);
		int cnt = 0;
		for(int j = 1; j <= N; ++j) {
			if(color[j]) ++cnt;
		}
		mxcnt = max(mxcnt, cnt);
	}
	cout << mxcnt << '\n';
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

