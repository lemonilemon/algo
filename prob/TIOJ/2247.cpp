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
const int MAXC = 26;
const ll INF = 1e18 + 7;
vector<string> keyboard = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
vector<int> graph[MAXC];
map<char, int> mp;
int color[MAXC];
int dis[MAXC][MAXC];
void init() {
	int cnt = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < (int)keyboard[i].size(); ++j) {
			mp[keyboard[i][j]] = cnt;
			if(i) {
				graph[cnt].emplace_back(mp[keyboard[i - 1][j]]);
				graph[mp[keyboard[i - 1][j]]].emplace_back(cnt);
				graph[cnt].emplace_back(mp[keyboard[i - 1][j + 1]]);
				graph[mp[keyboard[i - 1][j + 1]]].emplace_back(cnt);
			}
			if(j) {
				graph[cnt].emplace_back(mp[keyboard[i][j - 1]]);
				graph[mp[keyboard[i][j - 1]]].emplace_back(cnt);
			}
			++cnt;
		}
	}
	for(int i = 0; i < MAXC; ++i) {
		for(int j = 0; j < MAXC; ++j) {
			color[j] = 0;
		}
		queue<int> que;
		que.push(i);
		color[i] = 1;
		dis[i][i] = 0;
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(auto v : graph[u]) {
				if(color[v]) continue;
				que.push(v);
				color[v] = 1;
				dis[i][v] = dis[i][u] + 1;
			}
			color[u] = 2;
		}
	}
}
ll dp[2][MAXC][MAXC];
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < MAXC; ++i) {
		for(int j = 0; j < MAXC; ++j) {
			dp[0][i][j] = INF;
		}
	}
	dp[0][mp['F']][mp['J']] = 0;
	for(int c = 1; c <= n; ++c) {
		int k = mp[s[c - 1]];
		for(int i = 0; i < MAXC; ++i) {
			for(int j = 0; j < MAXC; ++j) {
				dp[c & 1][i][j] = INF;
			}
		}
		for(int i = 0; i < MAXC; ++i) {
			for(int j = 0; j < MAXC; ++j) {
				dp[c & 1][i][k] = min(dp[c & 1][i][k], dp[!(c & 1)][i][j] + dis[j][k]);
			}
		}
		for(int i = 0; i < MAXC; ++i) {
			for(int j = 0; j < MAXC; ++j) {
				dp[c & 1][k][i] = min(dp[c & 1][k][i], dp[!(c & 1)][j][i] + dis[j][k]);
			}
		}
	}
	ll ans = INF;
	for(int i = 0; i < MAXC; ++i) {
		for(int j = 0; j < MAXC; ++j) {
			ans = min(ans, dp[n & 1][i][j]);
		}
	}
	cout << ans << '\n';
}

int main() {
	setIO();
	int T = 1;
	init();
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

