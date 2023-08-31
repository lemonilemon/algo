#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5; 
int pos[MAXN];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        pos[p] = i;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(pos[i] < pos[i - 1]) ++cnt;
    }
    cout << cnt << '\n';
}
int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
