#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int p[MAXN], pos[MAXN];
int cnt;
void change(int x, int y) {
    if(x == y) return;
    swap(p[x], p[y]);
    swap(pos[p[x]], pos[p[y]]);
    --cnt;
}
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cerr << pos[i] << " \n"[i == n];
    }
    priority_queue<int, vector<int>, greater<> > pq;
    cnt = n - k + 1;
    for(int i = 1; i <= k; ++i) {
        pq.push(p[i]);
    }
    change(pos[pq.top()], 1);
    pq.pop();
    /*for(int j = 1; j <= n; ++j) {
        cerr << p[j] << " \n"[j == n];
    }*/
    for(int i = 2; i <= n && cnt > 0; ++i) {
        int r = i + k - 1;
        if(r <= n) pq.push(r);
        change(pos[pq.top()], i);
        pq.pop();
        /*for(int j = 1; j <= n; ++j) {
            cerr << p[j] << " \n"[j == n];
        }*/
    }
    for(int i = 1; i <= n; ++i) {
        cout << p[i] << " \n"[i == n];
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
