#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 1e5 + 5, MAXM = 1e5 + 5, MAXK = 21;

int a[MAXN];
pair<int, int> e[MAXM];
ll c[MAXK];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> e[i].first >> e[i].second;
    }
    for(int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    ll ans = 0;
    for(int i = 0; i < (1 << k); ++i) {
        bool flag = 1;
        for(int j = 0; j < m; ++j) {
            int u = e[j].first, v = e[j].second; 
            if((i & (1 << a[u])) && (i & (1 << a[v])) && a[u] != a[v]) {
               flag = 0;
               break; 
            }
        }
        if(flag) {
            ll cnt = 0;
            for(int j = 0; j < k; ++j) {
                if(i & (1 << j)) cnt += c[j];
            }
            ans = max(cnt, ans);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
