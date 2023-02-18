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
const int MAXM = 1e5 + 5;
vector<int> graph[MAXM << 1], scc[MAXM << 1], stk;
int cond[MAXM << 1], inscc[MAXM << 1], color[MAXM << 1], low[MAXM << 1], t[MAXM << 1];
bool instk[MAXM << 1];
int timer, scccnt;
void tarjan(int u) {
	color[u] = 1;
	low[u] = t[u] = ++timer;
	instk[u] = 1;
	stk.push_back(u);
	for(auto v : graph[u]) {
		if(!color[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) {
			low[u] = min(low[u], t[v]);
		}
	}
	color[u] = 2;
	if(t[u] == low[u]) {
		++scccnt;
		while(stk.back() != u) {
			inscc[stk.back()] = scccnt;
			scc[scccnt].push_back(stk.back());
			instk[stk.back()] = 0;
			stk.pop_back();
		}
		inscc[stk.back()] = scccnt;
		scc[scccnt].push_back(stk.back());
		instk[stk.back()] = 0;
		stk.pop_back();
	}
}
int sccans[MAXM << 1], ans[MAXM];
void findscc(int n) {
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) tarjan(i);
	}
	for(int i = 1; i <= n; ++i) {
		color[i] = 0;
	}
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		char c1, c2;
		int x1, x2;
		cin >> c1 >> x1 >> c2 >> x2;
		bool b1 = c1 == '+', b2 = c2 == '+'; // '+' : 2, 4, 6, 8
		int u = (x1 << 1) + !b1 - 1, v = (x2 << 1) + b2 - 1; // 1 : false, 2 : true	
		graph[u].push_back(v);
		u = (x2 << 1) + !b2 - 1, v = (x1 << 1) + b1 - 1; // 1 : true, 2 : false	 
		graph[u].push_back(v);
	}
	findscc(M << 1);
	for(int i = 1; i <= M; ++i) {
		if(inscc[(i << 1) - 1] == inscc[i << 1]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	for(int i = 1; i <= scccnt; ++i) {
		sccans[i] = -1;
	}
	for(int i = 1; i <= scccnt; ++i) {
		if(sccans[i] == -1) sccans[i] = 1;
		for(auto u : scc[i]) {
			int cur = (u >> 1) + (u & 1);
			bool pos = !(u & 1);
			int v = (cur << 1) - 1 + !pos;
			sccans[inscc[v]] = !sccans[i]; 
		}
	}
	for(int i = 1; i <= M; ++i) {
		if(sccans[inscc[i << 1]]) cout << '+';
		else cout << '-';
		cout << " \n"[i == M];
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

