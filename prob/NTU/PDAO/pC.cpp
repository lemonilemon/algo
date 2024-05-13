#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 1e6 + 5;
const ll INF = 1e18;
vector<int> child[MAXN];
ll dp[MAXN][2];
int par[MAXN];
int cost[MAXN];
void dfs(int u) {
    dp[u][0] = 0;
    dp[u][1] = cost[u];
    for(auto v: child[u]) {
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    return;
}
void solve() {
    int n;
    cin >> n;
    int root = -1;
    for(int i = 0; i < n; ++i) {
        cin >> par[i];
        if(par[i] == -1) {
            root = i;
        } else child[par[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    if(n == 1) {
        cout << cost[0] << '\n';
        return;
    }
    dfs(root);
    cout << min(dp[root][0], dp[root][1]) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
