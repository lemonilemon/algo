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
const ll INF = 1e18 + 9;
struct MF {
	int n, S, T;
	struct Edge {
		int v, nxt;
		ll cap, flow;
	} e[MAXM << 2];
	int head[MAXN], cnt;
	void addedge(int u, int v, int w) {
		e[cnt] = {v, head[u], w, 0};
		head[u] = cnt++;
		e[cnt] = {u, head[v], w, 0};
		head[v] = cnt++;
	}
	int dep[MAXN], color[MAXN];	
	bool bfs() {
		for(int i = 0; i <= n; ++i) {
			color[i] = 0;
		}
		queue<int> que;
		que.push(S);
		dep[S] = 0;
		color[S] = 1;
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if(color[v]) continue;
				if(e[i].cap - e[i].flow > 0) {
					que.push(v);
					color[v] = 1;
					dep[v] = dep[u] + 1;
				}
			}
			color[u] = 2;
		}
		return color[T];
	}

	int cur[MAXN];	
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

	ll maxflow;	
	void dinic() {
		maxflow = 0;
		while(bfs()) {
			for(int i = 0; i <= n; ++i) {
				cur[i] = head[i];
			}
			maxflow += dfs(S, INF);
		}
	}
	void redfs(int u) {
		color[u] = 1;
		for(int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].v;
			if(color[v]) continue;
			if(e[i].cap - e[i].flow > 0) redfs(v);
		}
		color[u] = 2;
	}
	vector<pair<int, int> > cut;
	void cutedge() {
		for(int i = 0; i <= n; ++i) {
			color[i] = 0;
		}
		redfs(S);
		for(int u = 0; u <= n; ++u) {
			if(!color[u]) continue; //color[u] != 0
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if(color[v]) continue; //color[v] == 0
				cut.emplace_back(make_pair(u, v));
			}
		}
	}

	MF(int n, int S, int T): n(n), S(S), T(T), cnt(0), maxflow(0) {
		for(int i = 0; i <= n; ++i) {
			head[i] = -1;
		}
	}
};
int color[MAXN];
void solve() {
	int n, m;
	cin >> n >> m;
	MF mf(n, 1, n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		mf.addedge(u, v, 1);
	}
	mf.dinic();
	cout << mf.maxflow << '\n';
	mf.cutedge();
	for(auto [u, v] : mf.cut) {
		cout << u << ' ' << v << '\n';
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

