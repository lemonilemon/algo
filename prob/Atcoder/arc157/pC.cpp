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
const int MAXH = 2005, MAXW = 2005, MOD = 998244353;
int comb[MAXH << 1][MAXW];
int dp1[2][MAXW];
int dp2[2][MAXW];
char mat[2][MAXW];
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b); 
}
void init() {
	for(int i = 0; i < (MAXH << 1); ++i) {
		comb[i][0] = 1;
	}
	for(int i = 1; i < (MAXH << 1); ++i) {
		for(int j = 1; j < MAXW; ++j) {
			comb[i][j] = madd(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}
}
void solve() {
	int H, W;
	cin >> H >> W;
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			cin >> mat[i & 1][j];
			dp1[i & 1][j] = madd(dp1[!(i & 1)][j], dp1[i & 1][j - 1]);
			dp2[i & 1][j] = madd(dp2[!(i & 1)][j], dp2[i & 1][j - 1]);
			if(mat[i & 1][j] == 'Y') {
				if(mat[i & 1][j] == mat[!(i & 1)][j]) {
					dp1[i & 1][j] = madd(dp1[i & 1][j], comb[i + j - 3][i - 2]);
					dp2[i & 1][j] = madd(dp2[i & 1][j], madd(mmul(2, dp1[!(i & 1)][j]), comb[i + j - 3][i - 2]));
				}
				if(mat[i & 1][j] == mat[i & 1][j - 1]) {
					dp1[i & 1][j] = madd(dp1[i & 1][j], comb[i + j - 3][i - 1]);
					dp2[i & 1][j] = madd(dp2[i & 1][j], madd(mmul(2, dp1[i & 1][j - 1]), comb[i + j - 3][i - 1]));
				}
			}	
		}
	}
	cout << dp2[H & 1][W] << '\n';
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	init();
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

