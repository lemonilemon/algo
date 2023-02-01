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
const int MAXN = 505, MAXM = 505;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char mat[MAXN][MAXM];
int color[MAXN][MAXM];
void dfs(int x, int y) {
	color[x][y] = 1;
	for(int d = 0; d < 4; ++d) {
		int vx = dx[d] + x, vy = dy[d] + y;
		if(mat[vx][vy] == '#' || color[vx][vy]) continue;
		dfs(vx, vy);
	}
	color[x][y] = 2;
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i <= N + 1; ++i) {
		for(int j = 0; j <= M + 1; ++j) {
			mat[i][j] = '#'; //wall
			color[i][j] = 0;
		}
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(mat[i][j] == 'B') {
				for(int d = 0; d < 4; ++d) {
					int vx = dx[d] + i, vy = dy[d] + j;
					if(mat[vx][vy] == 'G') {
						cout << "No\n";
						return;
					}
					if(mat[vx][vy] != 'B') mat[vx][vy] = '#';
				}
			}
		}
	}
	if(mat[N][M] != '#') dfs(N, M);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if((mat[i][j] == 'B' && color[i][j]) || (mat[i][j] == 'G' && !color[i][j])) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main() {
	setIO();
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

