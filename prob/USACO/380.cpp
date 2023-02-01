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
FILE* setIO(string file = "ccski") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int INF = 2e9 + 7;
const int MAXM = 505, MAXN = 505;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int elev[MAXM][MAXN];
bool waypoint[MAXM][MAXN];
int color[MAXM][MAXN];
int D, M, N;
void dfs(int x, int y) {
	color[x][y] = 1;
	for(int d = 0; d < 4; ++d) {
		int vx = dx[d] + x, vy = dy[d] + y;
		if(color[vx][vy] || abs(elev[x][y] - elev[vx][vy]) > D) continue;
		dfs(vx, vy);
	}
	color[x][y] = 2;
}
bool check() {
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			color[i][j] = 0;
		}
	}
	bool flag = 0;
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			if(waypoint[i][j]) {
				if(color[i][j]) continue;
				if(flag) return 0;
				flag = 1;
				dfs(i, j);
			}
		}
	}
	return 1;
}
void solve() {
	cin >> M >> N;
	for(int i = 0; i <= M + 1; ++i) {
		for(int j = 0; j <= N + 1; ++j) {
			elev[i][j] = INF;
		}
	}
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin >> elev[i][j];
		}
	}
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin >> waypoint[i][j];
		}
	}
	int l = -1, r = 1e9;
	while(r - l > 1) {
		D = (l + r) >> 1;
		if(check()) r = D;
		else l = D;
	}	
	cout << r << '\n';
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

