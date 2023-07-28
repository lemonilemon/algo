#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 2e5 + 5;
const ll INF = 1e12 + 7;
struct S {
    pair<ll, ll> l, r;
};
pair<ll, ll> p[MAXN];
int n;
pair<ll, ll> ans;
bool check(ll k) {
    S cur = {{0, 0}, {INF << 1, INF << 1}};
    for(int i = 0; i < n; ++i) {
        auto x = p[i].first, y = p[i].second;
        pair<ll, ll> l, r;
        l = make_pair(x - k, y - k);
        r = make_pair(x + k, y + k);
        cur.l.first = max(cur.l.first, x - k);
        cur.l.second = max(cur.l.second, y - k);
        cur.r.first = min(cur.r.first, x + k);
        cur.r.second = min(cur.r.second, y + k);
        if(cur.r.first < cur.l.first || cur.r.second < cur.l.second) return 0;
    }
    ans = cur.l;
    return 1;    
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    ll l = -1, r = 1e9 + 7;
    while(r - l > 1) {
        ll mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    cout << ans.first << ' ' << ans.second << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
