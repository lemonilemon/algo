#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], cnt[MAXN];
int mabs(int a, int mod) {
    return (a % mod + mod) % mod;
}
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; ++i) {
        a[i] = 0;
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        ++cnt[a[i]];
    }
    int mex = 0, mexmex = -1;
    while(cnt[mex]) ++mex;
    for(int i = 1; i <= n; ++i) {
        // cerr << mex << ' ' << mexmex << '\n';
        int val = a[i];
        if(~mexmex) {
            a[i] = mexmex;
            mexmex = -1;
        } else {
            while(cnt[mex]) ++mex;
            a[i] = mex;
        }
        --cnt[val];
        ++cnt[a[i]];
        if(!cnt[val] && val < mex) mexmex = val;
    }
    mex = 0;
    while(cnt[mex]) ++mex;
    for(int i = 0; i < n; ++i) {
        b[i] = a[i + 1];
    }
    b[n] = mex;
    for(int i = 0; i < n; ++i) {
        cout << b[mabs(i - k + 1, n + 1)] << " \n"[i == n - 1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
