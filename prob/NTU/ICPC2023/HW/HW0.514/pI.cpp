#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
void solve() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a, a + n, [](int x, int y) {
        return x > y;
    });
    sort(b, b + n);
    int i = 0, j = 0;
    for(; i < n && j < n; ++i, ++j) {
        if(a[i] + b[j] < x) --i; 
    }
    cout << 1 << ' ' << i << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
