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
const int MAXN = 1e5 + 5;
vector<string> vals;
vector<int> graph[MAXN << 1];
string s[MAXN], t[MAXN];
int ds[MAXN], dt[MAXN];
int color[MAXN << 1];
bool flag = 0;
void dfs(int u) {
	color[u] = 1;
	for(auto v : graph[u]) {
		if(color[v]) {
			if(color[v] == 1) flag = 1;
			continue;
		}
		dfs(v);
	}
	color[u] = 2;
}
void solve() {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> s[i] >> t[i];
		vals.push_back(s[i]);
		vals.push_back(t[i]);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for(int i = 0; i < N; ++i) {
		ds[i] = lower_bound(vals.begin(), vals.end(), s[i]) - vals.begin() + 1;
		dt[i] = lower_bound(vals.begin(), vals.end(), t[i]) - vals.begin() + 1;	
		graph[ds[i]].push_back(dt[i]);
	}
	for(int i = 1; i <= (int)vals.size(); ++i) {
		if(!color[i]) {
			dfs(i);
		}
	}
	if(flag) cout << "No\n";
	else cout << "Yes\n"; 
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

