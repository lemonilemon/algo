/* 
 * Created : 2024-07-29 11:18:10 lemonilemon
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
const int MAXN = 1e6 + 5;
const int MAXK = 1e3 + 5;
const int INF = 1e9 + 7;
int a[MAXN];
int dis[MAXK];
pair<int, string> backtrack[MAXK];
vector<pair<int, string> > graph[MAXK];
map<pair<int, int>, string> mp;

// solution
void solve() {
    int n, k;
    cin >> n >> k;
    stringstream ss;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        int mod = a[i] % k;
        ss << a[i];
        string s;
        ss >> s;
        ss.str("");
        ss.clear();
        mp[make_pair(mod, s.size())] = s;
    }
    for(auto [p, s] : mp) {
        auto [mod, len] = p;
        int mul = 1;
        for(int i = 0; i < len; ++i) {
            mul *= 10;
            mul %= k;
        }
        for(int i = 0; i <= k; ++i) {
            int nxt = (i * mul + mod) % k; 
            graph[i].push_back(make_pair(nxt, s));
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    for(int i = 0; i < k; ++i) {
        dis[i] = INF;
    }
    dis[k] = 0;
    pq.push(make_pair(0, k));
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dis[u]) continue;
        for(auto [v, s] : graph[u]) {
            int len = s.size();
            if(d + len < dis[v]) {
                dis[v] = d + len;
                pq.push(make_pair(dis[v], v));
                backtrack[v] = make_pair(u, s);
            }
        }
    }
    if(dis[0] == INF) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<string> ans;
    int cur = 0;
    while(cur != k) {
        auto [pre, s] = backtrack[cur];
        ans.push_back(s);
        cur = pre;
    }
    reverse(ans.begin(), ans.end());
    for(auto s : ans) {
        cout << s;
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

