/* 
 * Created : 2023-10-06 05:26:05 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


#define LOCAL

// debug template
#ifdef LOCAL
#define debug(args...) _debug(#args, args)
#define expand(arr, l, r) _expand(#arr, l, r, begin(arr) + l, begin(arr) + r)
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0) 
#define safe() ((void)0) 
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 2e5 + 5;
ll bit[MAXN << 1];
ll query(int k) {
    ll ret = 0;
    for(; k > 0; k ^= k & -k) ret = max(bit[k], ret);
    return ret;
}
void modify(int k, ll val) {
    for(; k < (MAXN << 1); k += k & -k) bit[k] = max(val, bit[k]);
}
struct Point {
    int x, y;
    ll val;
} p[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    vector<int> xyvals;
    for(int i = 0; i < n; ++i) {
        auto& [x, y, v] = p[i];
        cin >> x >> y >> v;
        xyvals.push_back(x), xyvals.push_back(y);
    }
    sort(xyvals.begin(), xyvals.end());
    xyvals.erase(unique(xyvals.begin(), xyvals.end()), xyvals.end());
    for(int i = 0; i < n; ++i) {
        auto& [x, y, v] = p[i];
        x = lower_bound(xyvals.begin(), xyvals.end(), x) - xyvals.begin() + 1;
        y = lower_bound(xyvals.begin(), xyvals.end(), y) - xyvals.begin() + 1;
    }
    sort(p, p + n, [](Point a, Point b) {
        return a.x == b.x? a.y < b.y : a.x < b.x;
    });
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        auto [x, y, v] = p[i];
        // debug(x, y, v);
        ll curdp = query(y) + v;
        ans = max(ans, curdp);
        modify(y, curdp);
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

