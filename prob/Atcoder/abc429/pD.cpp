/*
 * Created : 2025-10-25 20:07:52 lemonilemon
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
const int MAXN = 5e5 + 5;
ll a[MAXN];
int cnt[MAXN];
ll prefix_cnt[MAXN];
// solution
void solve() {
    int n, c;
    ll m;
    cin >> n >> m >> c;
    vector<ll> vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        ++cnt[a[i]];
    }
    for (int i = 1; i <= vals.size(); ++i) {
        prefix_cnt[i] = prefix_cnt[i - 1] + cnt[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < vals.size(); ++i) {
        ll st_points_cnt =
            i ? vals[i] - vals[i - 1] : (vals.front() - vals.back()) % m + m;
        ll people_cnt = 0;
        debug(i, prefix_cnt[vals.size()], prefix_cnt[i]);
        if (prefix_cnt[vals.size()] - prefix_cnt[i] < c) {
            people_cnt += prefix_cnt[vals.size()] - prefix_cnt[i];
            people_cnt +=
                *lower_bound(prefix_cnt, prefix_cnt + vals.size() + 1,
                             c - (prefix_cnt[vals.size()] - prefix_cnt[i]));
        } else {
            people_cnt =
                *lower_bound(prefix_cnt + i + 1, prefix_cnt + vals.size() + 1,
                             prefix_cnt[i] + c) -
                prefix_cnt[i];
        }
        debug(vals[i], st_points_cnt, people_cnt);
        ans += 1ll * st_points_cnt * people_cnt;
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
