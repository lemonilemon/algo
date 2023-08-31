/* 
 * Created : 2023-08-30 14:54:52 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


#define LOCAL

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
#endif

// constants
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const ll INF = 1e18 + 9;
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
// solution
void solve() {
    int l, r;
    cin >> l >> r;
    int m;
    cin >> m;
    int s = l + r, t = l + r + 1;
    mf.init(l + r + 2, s, t);
    for(int i = 0; i < m; ++i) {
       int u, v;
       cin >> u >> v;
       mf.addedge(u, l + v, 1);
    }
    for(int i = 0; i < l; ++i) {
       mf.addedge(s, i, 1);
    }
    for(int i = l; i < l + r; ++i) {
       mf.addedge(i, t, 1);
    }
    mf.dinic();
    cout << mf.maxflow << '\n';
    for(int u = 0; u < l; ++u) {
        for(int i = mf.head[u]; ~i; i = mf.e[i].nxt) {
            int v = mf.e[i].v; 
            if(mf.e[i].flow > 0 && mf.e[i].cap == mf.e[i].flow) {
                cout << u << ' ' << v - l << '\n';
            }
        }
    }
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

