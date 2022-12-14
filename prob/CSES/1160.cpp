#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
void safe() {
	std::cerr<<"\033[1;32m"<<__PRETTY_FUNCTION__<<" is safe\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
const int MAXN = 2e5 + 5;
int mabs(ll a, int mod) {
	return (a % mod + mod) % mod;
}
int cyclecnt;
int t[MAXN], color[MAXN], dis[MAXN];
vector<int> cycle[MAXN];
pair<int, int> incycle[MAXN];
vector<int> stk;
void dfs(int u) {
	color[u] = 1;
	stk.push_back(u);
	int v = t[u];
	if(!color[v]) {
		dfs(v);
		incycle[u] = incycle[v];
		if(incycle[u]) dis[u] = dis[v] + 1;
	} else if(color[v] == 1) {
		++cyclecnt;
		auto st = stk.begin();
		while(*st != v) ++st;	
	} else {
		incycle[u] = incycle[v];
		incycle[u].second;
	}
	stk.pop_back();
	color[u] = 2;
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) {

		}
	}
	for(int i = 1; i <= n; ++i) {
		debug(i), debug(incycle[i].first), debug(incycle[i].second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

