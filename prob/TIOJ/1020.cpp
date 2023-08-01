#include <bits/stdc++.h>
using namespace std;
int n, cnt;
vector<int> ans;
void dfs(int u = 2, const vector<int>& v = {0, 1}) {
    if(u > n) {
        ++cnt;
        if(v > ans) ans = v;
        return;
    }
    for(int i = 1; i < u; ++i) {
        if(u % (v[i] + v[i - 1])) continue;
        vector<int> ret;
        for(int j = 0; j < v.size(); ++j) {
            if(j == i) ret.push_back(u);
            ret.push_back(v[j]);
        }
        dfs(u + 1, ret);
    }
}
void solve() {
    cin >> n;
    dfs();
    cout << cnt << '\n';
    if(cnt) {
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
