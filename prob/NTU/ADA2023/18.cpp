/* 
 * Created : 2023-11-22 06:10:02 lemonilemon
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
const int MAXN = 1e6 + 5;
vector<int> graph[MAXN];
int t[MAXN], p[MAXN], low[MAXN];
int timer;
bool instk[MAXN], color[MAXN];
int inscc[MAXN];
vector<vector<int> > sccs;
vector<int> stk;
void dfs(int u) {
    instk[u] = 1;
    stk.push_back(u);
    low[u] = t[u] = ++timer;
    color[u] = 1;
    for(auto v : graph[u]) {
        if(color[v]) {
            if(instk[v]) low[u] = min(low[u], t[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(t[u] == low[u]) {
        sccs.push_back(vector<int>());
        while(stk.back() != u) {
            sccs.back().push_back(stk.back());
            inscc[stk.back()] = sccs.size() - 1;
            instk[stk.back()] = 0;
            stk.pop_back();
        }
        sccs.back().push_back(u);
        inscc[u] = sccs.size() - 1;
        instk[u] = 0;
        stk.pop_back();
    }
}
vector<vector<int> > sccgraph;
void build() {
    sccgraph.clear();
    sccgraph.resize(sccs.size());
    for(int sccu = 0; sccu < sccs.size(); ++sccu) {
        auto& scc = sccs[sccu];
        for(auto u : scc) {
            for(auto v : graph[u]) {
                if(inscc[u] == inscc[v]) continue;
                int sccv = inscc[v];
                sccgraph[sccu].push_back(sccv);
            }
        }
    }
    for(int i = 0; i < sccs.size(); ++i) {
        sort(sccgraph[i].begin(), sccgraph[i].end());
        sccgraph[i].erase(unique(sccgraph[i].begin(), sccgraph[i].end()), sccgraph[i].end());
    }
}
void rbuild() {
    sccgraph.clear();
    sccgraph.resize(sccs.size());
    for(int sccu = 0; sccu < sccs.size(); ++sccu) {
        auto& scc = sccs[sccu];
        for(auto u : scc) {
            for(auto v : graph[u]) {
                if(inscc[u] == inscc[v]) continue;
                int sccv = inscc[v];
                sccgraph[sccv].push_back(sccu);
            }
        }
    }
    for(int i = 0; i < sccs.size(); ++i) {
        sort(sccgraph[i].begin(), sccgraph[i].end());
        sccgraph[i].erase(unique(sccgraph[i].begin(), sccgraph[i].end()), sccgraph[i].end());
    }
}


// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i) {
        if(!color[i]) dfs(i);
        debug(i, inscc[i]);
    }
    int ans = 0;
    for(int t = 0; t < 2; ++t) {
        if(t) rbuild();
        else build();
        int sccn = sccs.size();
        vector<int> sccindeg(sccn, 0);
        vector<int> sccdp(sccn, 0);
        for(int i = 0; i < sccn; ++i) {
            for(auto v : sccgraph[i]) {
                ++sccindeg[v];
            }
        }
        safe();
        queue<int> que;
        for(int i = 0; i < sccn; ++i) {
            if(!sccindeg[i]) que.push(i);
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            ans = max(ans, sccdp[u] += sccs[u].size());
            for(auto v : sccgraph[u]) {
                sccdp[v] = max(sccdp[u], sccdp[v]);
                if(!(--sccindeg[v])) que.push(v);
            }
        }
    }
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

