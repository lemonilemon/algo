/* 
 * Created : 2023-12-29 11:34:12 lemonilemon
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
const int MAXN = 1e5 + 5; 
vector<int> graph[MAXN];
int seq[2][MAXN];
int ord[MAXN];
int indeg[MAXN];
int cnt[2];
bool color[2][MAXN];


// solution
void solve() {
    int n;
    for(int t = 0; t < 2; ++t) {
        int m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            indeg[i] = 0;
            graph[i].clear();
        }
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            ++indeg[v];
        }
        priority_queue<int, vector<int>, greater<int> > pq;  
        for(int i = 0; i < n; ++i) {
            if(!indeg[i]) {
                pq.push(i);
            }
        }
        int cur = 0;
        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();
            // debug(t, u);
            seq[t][cnt[t]++] = u;
            color[t][u] = 1;
            for(auto v : graph[u]) {
                --indeg[v];
                if(!indeg[v]) {
                    pq.push(v);
                }
            }
        }
    } 
    for(int i = 0; i < cnt[0]; ++i) {
        ord[seq[0][i]] = i; 
    }
    vector<int> LIS;
    for(int i = 0; i < cnt[1]; ++i) {
        if(!color[seq[1][i]]) continue;
        if(LIS.empty() || ord[seq[1][i]] > LIS.back()) {
            LIS.push_back(ord[seq[1][i]]);
            continue;
        }
        auto p = lower_bound(LIS.begin(), LIS.end(), ord[seq[1][i]]);
        *p = ord[seq[1][i]];
    }
    cout << LIS.size() << '\n';
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
