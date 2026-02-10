/*
 * Created : 2026-02-08 16:53:49 lemonilemon
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
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
bool check(int x, int n, ll m, map<int, ll> mp) {
    ll cnt = 0;
    ll total = n + m;
    for (auto [v, f] : mp) {
        if (v >= x)
            cnt += f;
    }
    debug(x, m, cnt);
    while (m > 0) {
        debug(x, m, cnt, total);
        auto p = prev(mp.end());
        ll t = min(p->second, m);
        if (p->first >= 2 * x - 1) {
            debug(p->first, t);
            int val1 = p->first / 2;
            int val2 = (p->first + 1) / 2;
            if (val1 >= x)
                cnt += t;
            mp[val1] += t;
            mp[val2] += t;
            p->second -= t;
        } else {
            if (2 * cnt < total)
                return false;
            p = mp.begin();
            t = min(p->second, m);
            if (p->first < x) {
                debug(p->first, t);
                m -= 1ll * p->second * (p->first - 1);
                mp.erase(p);
                continue;
            } else {
                p = prev(mp.end());
                t = min(min(p->second, m), cnt - (total + 1) / 2);
                debug(p->first, t);
                int val1 = p->first / 2;
                int val2 = (p->first + 1) / 2;
                mp[val1] += t;
                mp[val2] += t;
                cnt -= t;
                p->second -= t;
            }
        }
        if (p->second == 0)
            mp.erase(p);
        m -= t;
    }
    debug(x, n, m, cnt, total, mp.size());
    return 2 * cnt >= total;
}
// solution
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, ll> mp;
    for (auto &x : a) {
        cin >> x;
        ++mp[x];
    }
    int l = 1, r = 1e9 + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid, n, m, mp)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
