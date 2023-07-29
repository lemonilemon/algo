#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
vector<int> graph[MAXN];
bool color[MAXN];
int dis[MAXN];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }
    vector<int> up;
    for(int i = 1; i <= n; ++i) {
        int h;
        cin >> h;
        if(h == 1) up.push_back(i);
        else {
            int u = up.back();
            graph[u].push_back(i);
            graph[i].push_back(u);
            up.pop_back();
        }
    }
    queue<int> que;
    que.push(1);
    color[1] = 1;
    dis[1] = 0;
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(auto v : graph[u]) {
            cerr << u << ' ' << v << '\n';
            if(color[v]) continue; 
            dis[v] = dis[u] + 1;
            que.push(v);
            color[v] = 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        cerr << dis[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
