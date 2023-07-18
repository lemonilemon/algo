#include <bits/stdc++.h>
using namespace std;
void solve() {
   int n, m, k;
   cin >> n >> m >> k;
   int x0, y0;
   cin >> x0 >> y0;
   bool color = ((x0 & 1) ^ (y0 & 1));
   bool flag = 0;
   for(int i = 0; i < k; ++i) {
       int x, y;
       cin >> x >> y;
       if(color == ((x & 1) ^ (y & 1))) flag = 1;
   }
   if(flag) cout << "NO\n";
   else cout << "YES\n";
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
