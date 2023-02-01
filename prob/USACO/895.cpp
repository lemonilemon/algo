#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r,,)define safe() std::cerr << "\033[1;32m" << __PRETTY_FUNCTION__ << " is safe\033[0m\n"
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
FILE* setIO(string file = "perimeter") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 1005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool mat[MAXN][MAXN];
int color[MAXN][MAXN];
int blobcnt, area, peri;
void dfs(int x, int y) {
	color[x][y] = 1;
	++area;
	for(int i = 0; i < 4; ++i) {
		int vx = x + dx[i], vy = y + dy[i];
		if(mat[vx][vy]) {
			if(color[vx][vy]) continue;
			dfs(vx, vy);
		}
		else ++peri;	
	}
	color[x][y] = 2;
}
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			char ch;
			cin >> ch;
			mat[i][j] = (ch == '#');
		}
	}
	int mxarea = 0, mnperi = 0;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			if(mat[i][j] && !color[i][j]) {
				++blobcnt;
				area = 0;
				peri = 0;
				dfs(i, j);
				if(area > mxarea) {
					mxarea = area;
					mnperi = peri;
				} else if(area == mxarea) {
					mnperi = min(mnperi, peri);
				}
			}
		}
	}
	cout << mxarea << ' ' << mnperi << '\n';
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

