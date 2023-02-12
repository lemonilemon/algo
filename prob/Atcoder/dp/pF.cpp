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
const int MAXN = 3005;
int dp[MAXN][MAXN], backtrack[MAXN][MAXN]; // 0: (-1, 0), 1: (0, -1), 2: (-1, -1)
void solve() {
	string s, t;
	cin >> s >> t;
	dp[0][0] = 0;
	backtrack[0][0] = -1;
	for(int i = 1; i <= (int)s.size(); ++i) {
		dp[i][0] = 0;
		backtrack[i][0] = 0;
	}
	for(int i = 1; i <= (int)t.size(); ++i) {
		dp[0][i] = 0;
		backtrack[0][i] = 1;
	}
	for(int i = 1; i <= (int)s.size(); ++i) {
		for(int j = 1; j <= (int)t.size(); ++j) {
			if(dp[i - 1][j] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				backtrack[i][j] = 0;
			} else {
				dp[i][j] = dp[i][j - 1];
				backtrack[i][j] = 1;
			} 
			if(s[i - 1] == t[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;	
				backtrack[i][j] = 2;
			}
		}
	}
	string lcs;
	int sidx = s.size(), tidx = t.size();
	while(~backtrack[sidx][tidx]) {
		switch(backtrack[sidx][tidx]) {
			case 0:
				--sidx;
				break;
			case 1:
				--tidx;
				break;
			case 2:
				lcs.push_back(s[--sidx]);
				--tidx;
				break;
		}
	}
	reverse(lcs.begin(), lcs.end());
	cout << lcs << '\n';
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

