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
const int MAXN = 505, MAXM = 1005;
const ll INF = 1e18 + 7;
struct MF {
	struct Edge {
		int v, nxt;
		ll cap, flow;
	} e[MAXM << 1];
	int head[MAXN], cnt;
	int n, S, T;
	ll maxflow = 0;
	int dep[MAXN], color[MAXN], cur[MAXN];
	void init(int _n, int _S, int _T) {
		n = _n;
		S = _S;
		T = _T;
		for(int i = 0; i <= n; ++i) {
			head[i] = -1;
		}
		cnt = 0;
	}
	void addedge(int u, int v, ll w) {
		e[cnt] = {v, head[u], w, 0};
		head[u] = cnt++;
		e[cnt] = {u, head[v], 0, 0};
		head[v] = cnt++;
	}
	bool bfs() {
		queue<int> que;
		for(int i = 0; i <= n; ++i) {
			color[i] = 0;
		}
		dep[S] = 0;
		que.push(S);
		color[S] = 1;
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if(color[v]) continue;
				if(e[i].cap > e[i].flow) {
					dep[v] = dep[u] + 1;
					que.push(v);
					color[v] = 1;
				}
			}
			color[u] = 2;
		}
		return color[T];
	}

	ll dfs(int u, ll flow) {
		if(u == T || !flow) return flow;
		ll ret = 0;
		for(int& i = cur[u]; ~i; i = e[i].nxt) {
			int v = e[i].v;
			if(dep[v] != dep[u] + 1) continue;
			ll d = dfs(v, min(flow - ret, e[i].cap - e[i].flow));
			ret += d;
			e[i].flow += d;
			e[i ^ 1].flow -= d;
			if(ret == flow) return ret;	
		}
		return ret;
	}

	void dinic() {
		while(bfs()) {
			for(int i = 0; i <= n; ++i) {
				cur[i] = head[i];
			}
			maxflow += dfs(S, INF);
		}
	}
} mf;

void solve() {
	int n, m;
	cin >> n >> m;
	mf.init(n, 1, n);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		mf.addedge(u, v, w);
	}
	mf.dinic();
	cout << mf.maxflow << '\n';	
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

