/*
 * Created : 2025-10-25 00:10:44 lemonilemon
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
const int MAXN = 1e5 + 5;
int n;
int a[MAXN];
bool check(ll x) {
    set<pair<ll, int>> lmp, rmp;
    set<int> lock;
    for (int i = 0; i < n; ++i) {
        rmp.insert({a[i], i});
    }
    for (int i = 0; i < n; ++i) {
        rmp.erase({a[i], i});
        // debug(x, i, a[i], a[i] + x, a[i] - x);
        auto up = rmp.lower_bound({a[i] + x, 0});
        set<int> temp;
        if ((up != rmp.end()) && (next(up) != rmp.end())) {
            temp.insert(up->second);
            temp.insert(next(up)->second);
            temp.insert(i);
            if (next(next(up)) != rmp.end()) {
                // debug(next(next(up))->first, next(next(up))->second);
                temp.insert(next(next(up))->second);
            }
        }
        auto down = lmp.upper_bound({a[i] - x, n});
        // debug(down->first, down->second);
        if ((down != lmp.begin()) && (prev(down) != lmp.begin())) {
            temp.insert(prev(down)->second);
            temp.insert(prev(prev(down))->second);
            temp.insert(i);
            if (prev(prev(down)) != lmp.begin()) {
                temp.insert(prev(prev(prev(down)))->second);
            }
        }
        // cerr << "temp:";
        // for (auto t : temp) {
        //     cerr << " " << t;
        // }
        // cerr << '\n';
        lmp.insert({a[i], i});
        if (temp.size() >= 4) {
            temp.clear();
            temp.insert(i);
        }
        // cerr << "temp:";
        // for (auto t : temp) {
        //     cerr << " " << t;
        // }
        // cerr << '\n';
        if (!temp.empty()) {
            if (lock.empty()) {
                lock = temp;
            } else {
                set<int> result;
                set_intersection(lock.begin(), lock.end(), temp.begin(),
                                 temp.end(), inserter(result, result.begin()));
                if (result.empty())
                    return 1;
                lock = result;
            }
        }
        // cerr << "update lock:";
        // for (auto t : lock) {
        //     cerr << " " << t;
        // }
        // cerr << '\n';
    }
    return 0;
}
// solution
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = -1e9, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
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
