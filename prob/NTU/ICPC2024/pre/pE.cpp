/* 
 * Created : 2024-08-20 15:36:07 lemonilemon
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

const int MAXN = 2e6 + 5, MAXM = 2e6 + 5;
const ll INF = 1e18 + 7;
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
			if(color[v]) continue;
			if(e[i].cap - e[i].flow > 0) redfs(v);
		}
		color[u] = 2;
	}
	int mincut() {
		for(int i = 0; i <= n; ++i) {
			color[i] = 0;
		}
		redfs(S);
        ll ret = 0;
		for(int u = 0; u <= n; ++u) {
            // debug(u, color[u]);
			if(!color[u]) continue; //color[u] != 0
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if(color[v]) continue; //color[v] == 0
                ll w = e[i].cap;
                debug(u, v, w);
                ret += w; 
                if(ret > 20) return 21;
			}
		}
        return ret;
	}
 
	MF(int n, int S, int T): n(n), S(S), T(T), cnt(0), maxflow(0) {
		for(int i = 0; i <= n; ++i) {
			head[i] = -1;
		}
	}
} mf(MAXN - 1, 0, MAXN - 1);

int n;
int a[MAXN], c[MAXN], rev_a[MAXN];
int node[MAXN], lc[MAXN], rc[MAXN], tot; // 0: DNE
int insert(int x, int l, int r, int root) {
    int dir = ++tot;
    if(root) mf.addedge(dir + n + 2, root + n + 2, INF);
    lc[dir] = lc[root], rc[dir] = rc[root];
    if(l == r) {
        mf.addedge(dir + n + 2, x, INF);
        return dir;
    }
    int mid = (l + r) >> 1;
    if(a[x] <= mid) lc[dir] = insert(x, l, mid, lc[root]);
    else rc[dir] = insert(x, mid + 1, r, rc[root]);
    if(lc[dir]) mf.addedge(dir + n + 2, lc[dir] + n + 2, INF);
    if(rc[dir]) mf.addedge(dir + n + 2, rc[dir] + n + 2, INF);
    return dir;
}
void query(int val, int dest, int l, int r, int root) { // find all >= val
    if(!root || val > r) return;
    if(val <= l) {
        debug(dest + n + 2, root + n + 2, l, r);
        mf.addedge(dest + n + 2, root + n + 2, INF);
        return;
    }
    int mid = (l + r) >> 1;
    query(val, dest, l, mid, lc[root]);
    query(val, dest, mid + 1, r, rc[root]); 
}

vector<int> childs[MAXN];

void dfs(int u = 1, int p = 0) {
    node[u] = insert(u, 0, n, node[p]);
    int dest = ++tot;
    debug(u);
    query(a[u] + 1, dest, 0, n, node[p]);
    // debug(u, dest + n + 1, c[u]);
    mf.addedge(u, dest + n + 2, c[u]);
    for(auto v : childs[u]) {
        dfs(v, u);
    }
}
// solution
void solve() {
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        int s;
        cin >> s;
        childs[s].push_back(i);
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if(p >= 0) {
            ans += p;
            mf.addedge(n + 1, i, p);
        } else mf.addedge(i, n + 2, -p);
    }

    /*for(int u = 0; u <= n + 2; ++u) {
        for(int i = mf.head[u]; ~i; i = mf.e[i].nxt) {
            int v = mf.e[i].v;
            ll w = mf.e[i].cap;
            debug(u, v, w);
        }
    }*/
    

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        rev_a[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dfs();
    for(int i = 1; i <= n - 1; ++i) {
        int d;
        cin >> d;
        mf.addedge(rev_a[i + 1], rev_a[i], d);
    }

    mf.n = n + 2 + tot;
    mf.S = n + 1;
    mf.T = n + 2;

    
    

    mf.dinic();
    int mincut = mf.mincut();
    debug(mincut);
    ans -= mincut;
    if(mincut > 20) cout << "Fail!\n";
    else cout << ans << '\n';
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


