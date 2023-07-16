#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int cntabove[11];
int choose[11];
void dfs(int u = 1, int cur = 0) {
   if(u == 11) {
       if(cur == 10) {
            
       } 
       return;
   }
   for(int i = 0; cur + u * i <= 10; ++i) {
       choose[u] = i;
       dfs(u + 1, cur + u * i);
   }
}
void solve() {
    int n;
    cin >> n;
    int A[MAXN];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
