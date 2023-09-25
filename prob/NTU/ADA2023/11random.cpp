/* 
 * Created : 2023-09-22 11:35:17 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;
using pii = pair<ll, ll>;

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
const int MAXN = 1e5 + 5;
pii p[MAXN];
ll presum[MAXN];
pii operator - (pii a, pii b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
ll operator * (pii a, pii b) {
    return a.first * b.first + a.second * b.second;
}
ll dis2(pii a, pii b) {
    return (a - b) * (a - b); 
}
ll dis(pii a, pii b) {
    return ceil(sqrt(dis2(a, b)));
}
unordered_map<int, unordered_map<ll, vector<pii> > > mp;
// solution
void solve() {
    int n;
    cin >> n;
    p[0].first = 0;
    p[0].second = (int)1e9;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
        p[i].first = i;
        p[i].second = presum[i] + (int)(1e9);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    ll curdis2 = dis2(p[0], p[1]);
    for(int t = 0; t < 10; ++t) {
        shuffle(p, p + n + 1, default_random_engine(seed));
        for(int i = 2; i <= n; ++i) {
            curdis2 = min(curdis2, dis2(p[i], p[0]));
        }
    }
    ll curdis = ceil(sqrt(curdis2));
    //cerr << p[0].first << ' ' << p[0].second << '\n';
    //cerr << p[1].first << ' ' << p[1].second << '\n';
    mp[p[0].first / curdis][p[0].second / curdis].emplace_back(p[0]);
    mp[p[1].first / curdis][p[1].second / curdis].emplace_back(p[1]);
    // debug(curdis2, curdis);
    for(int i = 2; i <= n; ++i) {
        ll mndis2 = curdis2;
        for(int dx = -1; dx <= 1; ++dx) {
            ll curx = p[i].first / curdis, cury = p[i].second / curdis;
            for(int dy = -1; dy <= 1; ++dy) {
                ll x = curx + dx, y = cury + dy;
                if(!mp.count(x)) break;
                if(!mp[x].count(y)) continue;
                for(auto& u : mp[x][y]) {
                    mndis2 = min(dis2(u, p[i]), mndis2);
                }
            }
        }
        // debug(mndis2, curdis2);
        if(mndis2 < curdis2) {
            curdis2 = mndis2;
            curdis = ceil(sqrt(curdis2));
            mp.clear();
            for(int j = 0; j < i; ++j) {
                mp[p[j].first / curdis][p[j].second / curdis].emplace_back(p[j]);
            }
        }
        mp[p[i].first / curdis][p[i].second / curdis].emplace_back(p[i]);
    }
    cout << curdis2 << '\n';
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

