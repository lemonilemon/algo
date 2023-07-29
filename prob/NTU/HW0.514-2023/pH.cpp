#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
string r[MAXN];
unordered_map<string, int> rule_num;
vector<int> graph[MAXN];
int indeg[MAXN], color[MAXN];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
        rule_num[r[i]] = i;
    }
    for(int i = 0; i < m; ++i) {
        string w;
        int x;
        cin >> w >> x;
        for(int j = 0; j < k; ++j) {
            if(r[x][j] != w[j] && r[x][j] != '_') {
                cout << "NO\n";
                return;
            }
        }
        for(int j = 0; j < (1 << k); ++j) {
            string s = w;
            for(int l = 0; l < k; ++l) {
                if(j & (1 << l)) {
                    s[l] = '_';
                }
            }
            if(!rule_num.count(s)) continue;
            int v = rule_num[s];
            if(x != v) graph[x].push_back(v);
        }
    }
    for(int u = 1; u <= n; ++u) {
        for(auto v : graph[u]) {
            ++indeg[v];
        }
    }
    queue<int> que;
    for(int i = 1; i <= n; ++i) {
        if(!indeg[i]) que.push(i);
    }
    vector<int> ans;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for(auto v : graph[u]) {
            if(!(--indeg[v])) que.push(v);
        }
    }
    if((int)ans.size() == n) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    } else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
