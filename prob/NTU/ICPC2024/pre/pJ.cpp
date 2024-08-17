/* 
 * Created : 2024-08-17 10:53:16 lemonilemon
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
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 105;
const int MAXM = 155;

vector<int> max_matching(vector<vector<int>> g) {
    int n = g.size();
    vector<int> match(n + 1, n), pre(n + 1, n), que;
    vector<int> s(n + 1), mark(n + 1), pa(n + 1);
    function<int(int)> fnd = [&](int x) {
        if(x == pa[x]) return x;
        return pa[x] = fnd(pa[x]);
    };
    auto lca = [&](int x, int y) {
        static int tk = 0;
        tk++;
        x = fnd(x);
        y = fnd(y);
        for(;; swap(x, y))
            if(x != n) {
                if(mark[x] == tk)
                    return x;
                mark[x] = tk;
                x = fnd(pre[match[x]]);
            }
    };
    auto blossom = [&](int x, int y, int l) {
        while(fnd(x) != l) {
            pre[x] = y;
            y = match[x];
            if(s[y] == 1)
                que.push_back(y), s[y] = 0;
            if(pa[x] == x) pa[x] = l;
            if(pa[y] == y) pa[y] = l;
            x = pre[y];
        }
    };
    auto bfs = [&](int r) {
        fill(s.begin(), s.end(), -1);
        iota(pa.begin(), pa.end(), 0);
        que = {r}; s[r] = 0;
        for(int it = 0; it < que.size(); it++) {
            int x = que[it];
            for(int u : g[x]) {
                if(s[u] == -1) {
                    pre[u] = x;
                    s[u] = 1;
                    if(match[u] == n) {
                        for(int a = u, b = x, lst;
                        b != n; a = lst, b = pre[a]) {
                            lst = match[b];
                            match[b] = a;
                            match[a] = b;
                        }
                        return;
                    }
                    que.push_back(match[u]);
                    s[match[u]] = 0;
                }
                else if(s[u] == 0 && fnd(u) != fnd(x)) {
                    int l = lca(u, x);
                    blossom(x, u, l);
                    blossom(u, x, l);
                }
            }
        }
    };
    for(int i = 0; i < n; i++)
        if(match[i] == n) bfs(i);
    match.resize(n);
    for(int i = 0; i < n; i++)
        if(match[i] == n) match[i] = -1;
    return match;
}

vector<vector<int> > graph;
vector<pair<int, int> > edges;
int ans[MAXM];
int a[MAXN];
int deg[MAXN];
int presum[MAXN];
// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        --u, --v;
        ++deg[u];
        ++deg[v];
        edges.push_back({u, v});
    }
    presum[0] = min(deg[0], a[0]);
    for(int i = 1; i < n; ++i) {
        presum[i] = presum[i - 1] + min(deg[i], a[i]);
    }
    graph.resize(2 * m + presum[n - 1]);
    for(int i = 0; i < edges.size(); ++i) {
        auto [u, v] = edges[i];
        int left = presum[n - 1] + (i << 1), right = left + 1;
        graph[left].push_back(right);
        graph[right].push_back(left);
        for(int su = u? presum[u - 1] : 0; su < presum[u]; ++su) {
            graph[left].push_back(su);
            graph[su].push_back(left);
        }
        for(int sv = v? presum[v - 1] : 0; sv < presum[v]; ++sv) {
            graph[right].push_back(sv);
            graph[sv].push_back(right);
        }
    }
    auto match = max_matching(graph);
    /*
    for(auto x : match) {
        cerr << x << ' ';
    }
    cerr << '\n';
    for(int u = 0; u < graph.size(); ++u) {
        cerr << u << " : ";
               
        for(auto v : graph[u]) {
            cerr << v << ' ';
        }
        cerr << '\n';
    }
    */
    cout << count_if(match.begin(), match.end(), [&](int x) { return x != -1; }) / 2 - m << '\n';
    for(int u = 0; u < match.size(); ++u) {
        int v = match[u];
        if(v == -1) continue;
        if(u < presum[n - 1] && v >= presum[n - 1]) ++ans[((v - presum[n - 1]) >> 1) + 1];
    }
    for(int i = 1; i <= m; ++i) {
        if(ans[i] == 2) cout << i << ' ';
    }
    cout << '\n';
    
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


