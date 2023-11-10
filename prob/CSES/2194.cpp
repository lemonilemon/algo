/* 
 * Created : 2023-11-08 03:36:02 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


// #define LOCAL

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
using pii = pair<ll, ll>;
pii operator - (pii a, pii b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
ll operator * (pii a, pii b) {
    return a.first * b.first + a.second * b.second;
}
const int MAXN = 2e5 + 5;
ll INF = 8e18 + 7;
pii points[MAXN];
ll dq(int l, int r) {
    if(l == r) return INF;
    int mid = (l + r) >> 1;
    vector<pii> psl, psr;
    ll midx = points[mid].first;
    ll mn = min(dq(l, mid), dq(mid + 1, r));
    debug(l, r, mn);
    vector<pii> temp(r - l + 1);
    merge(points + l, points + mid + 1, points + mid + 1, points + r + 1, temp.begin(), [](const pii& a, const pii& b) {
        return a.second == b.second? a.first < b.first : a.second < b.second;
    });
    for(int i = l; i <= r; ++i) {
        points[i] = temp[i - l];
    }
    for(int i = l; i <= r; ++i) {
        debug(points[i].first, points[i].second);
    }
    vector<pii> ps;
    for(int i = l; i <= r; ++i) {
        if(abs(midx - points[i].first) <= ceil(sqrt(mn))) ps.push_back(points[i]);
    }
    for(int i = 0; i < ps.size(); ++i) {
        for(int j = i + 1; j <= i + 10 && j < ps.size(); ++j) {
            mn = min(mn, (ps[i] - ps[j]) * (ps[i] - ps[j]));
        }
    }
    debug(l, r, mn);
    return mn;
}
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        auto& [x, y] = points[i];
        cin >> x >> y;
    }
    sort(points, points + n);
    cout << dq(0, n - 1) << '\n';
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

