#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, MAXM = 1e6 + 5;
int a[MAXN], cnt[MAXM], fac[MAXM];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
       cin >> a[i]; 
       if(a[i] <= m) ++cnt[a[i]];
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; 1ll * i * j <= m; ++j){
            fac[i * j] += cnt[i];
        }
    }
    int lcm = 1, mxlen = 0;
    for(int i = m; i > 0; --i) {
        if(fac[i] >= mxlen) {
            mxlen = fac[i];
            lcm = i;
        }
    }
    cout << lcm << ' ' << mxlen << '\n';
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        if(!(lcm % a[i])) ans.push_back(i); 
    }
    assert(ans.size() == mxlen);
    for(int i = 0; i < mxlen; ++i) {
        cout << ans[i] << " \n"[i == mxlen - 1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
