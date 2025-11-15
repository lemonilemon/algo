/*
 * Created : 2025-11-14 22:59:18 lemonilemon
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

// solution
void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll cur = k;
    if (y == 1) {
        cout << "-1\n";
        return;
    }
    if (cur <= y - 1) {
        cout << cur << '\n';
        return;
    }
    ll op_left = x;
    while (op_left > 0) {
        ll dif = (cur + y - 2) / (y - 1) - 1;
        if (cur > (ll)1e12 || dif >= ((ll)1e12 - cur) / op_left + 1) {
            cout << "-1\n";
            return;
        }
        if (dif >= (int)1e6) {
            cur += dif;
            --op_left;
            continue;
        }
        ll target = (y - 1) * (dif + 1) + 1;
        ll need = (target - cur + dif - 1) / dif;
        if (need > op_left) {
            cur += op_left * dif;
            break;
        }
        cur += need * dif;
        op_left -= need;
    }
    if (cur > (ll)1e12) {
        cout << "-1\n";
        return;
    }
    cout << cur << '\n';
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
