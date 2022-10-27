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
const int MAXN = 1005;
bool mat[MAXN][MAXN];
int BIT[MAXN][MAXN];
void modify(int x, int y, int val) {
	for(int i = x; i < MAXN; i += i & -i) {
		for(int j = y; j < MAXN; j += j & -j) {
			BIT[i][j] += val;
		}
	}
}
int query(int x, int y) {
	int ret = 0;
	for(int i = x; i > 0; i -= i & -i) {
		for(int j = y; j > 0; j -= j & -j) {
			ret += BIT[i][j];
		}
	}
	return ret;
}
int count(int x1, int y1, int x2, int y2) {
	return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			char ch;
			cin >> ch;
			mat[i][j] = (ch == '*');
			if(ch == '*') modify(i, j, 1);
		}
	}
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int x, y;
			cin >> x >> y;
			if(mat[x][y]) modify(x, y, -1);
			else modify(x, y, 1);
			mat[x][y] = !mat[x][y];
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << count(x1, y1, x2, y2) << '\n';
		}
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

