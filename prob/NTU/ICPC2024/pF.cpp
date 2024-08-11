/* 
 * Created : {{_date_}} {{_author_}}
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


// #define LOCAL

// debug template
#ifdef LOCAL
#define debug(args...) _debug(#args, args)
#define expand(arr, l, r) _expand(#arr, l, r, begin(arr) + l, begin(arr) + r)
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0) 
#define safe() ((void)0) 
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 2e4 + 5, MAXM = 2e4 + 5;
const ll INF = 1e18 + 9;
struct MF {
	int n, S, T;
	struct Edge {
		int v, nxt;
		ll cap, flow;
	} e[MAXM << 2];
	int head[MAXN], cnt;
	void addedge(int u, int v, ll w) {
		e[cnt] = {v, head[u], w, 0};
		head[u] = cnt++;
		e[cnt] = {u, head[v], 0, 0};
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
            debug(u, v, e[i].cap, e[i].flow);
			if(color[v]) continue;
			if(e[i].cap - e[i].flow > 0) redfs(v);
		}
		color[u] = 2;
	}
	vector<ll> cut;
	void cutedge() {
		for(int i = 0; i <= n; ++i) {
			color[i] = 0;
		}
		redfs(S);
		for(int u = 0; u <= n; ++u) {
			if(!color[u]) continue; //color[u] != 0
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
                ll w = e[i].cap;
				if(color[v]) continue; //color[v] == 0
				cut.emplace_back(w);
			}
		}
	}
 
	MF(int n, int S, int T): n(n), S(S), T(T), cnt(0), maxflow(0) {
		for(int i = 0; i <= n; ++i) {
			head[i] = -1;
		}
	}
};
bool x[MAXN];
ll w[MAXN];



// solution
void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    MF mf(n + m + 2, 0, n + m + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
        if(x[i]) mf.addedge(i, mf.T, w[i]);
        else mf.addedge(mf.S, i, w[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= m; ++i) {
        bool y;
        ll v;
        int k;
        cin >> y >> v >> k;
        ans += v;
        for(int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            if(y) mf.addedge(a, n + i, INF);
            else mf.addedge(n + i, a, INF);
        }
        bool p;
        cin >> p;
        if(y) mf.addedge(n + i, mf.T, v + p * c);
        else mf.addedge(mf.S, n + i, v + p * c);
    }
    mf.dinic();  
    mf.cutedge();
    ll mincut = 0;
    for(auto val : mf.cut) {
        mincut += val;
    }
    ans -= mincut;
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
