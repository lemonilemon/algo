/*
 * Created : 2024-11-09 20:03:56 lemonilemon
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
const int MAXM = 2e5 + 5;
ll x[MAXM], a[MAXM];
pair<ll, ll> p[MAXM];
// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> p[i].first;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> p[i].second;
    }
    sort(p + 1, p + m + 1);
    for(int i = 1; i <= m; ++i) {
        x[i] = p[i].first;
        a[i] = p[i].second;
    }

    if(x[1] != 1) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    ll have = a[1];
    x[m + 1] = n;
    for(int i = 2; i <= m + 1; ++i) {
        ll dis = x[i] - x[i - 1];
        if(have < dis) {
            cout << "-1\n";
            return;
        }
        ans += have * dis;
        ans -= dis * (dis + 1) / 2;
        have -= dis;
        have += a[i];
    }
    if(have != 1) {
        cout << -1 << '\n';
        return;
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
