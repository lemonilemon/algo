/*
 * Created : 2025-11-03 21:15:42 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description :
 */

#include <bits/stdc++.h>
#include <ranges>
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

const int MAXN = 1e5 + 5;
vector<int> compute_z(const string &s) {
    vector<int> z(s.size());
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
    }
    return z;
}
// solution
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    auto z = compute_z(s);
    map<int, int> occurence;
    z[0] = n;
    for (int i = 0; i < n; ++i) {
        debug(i, z[i]);
        if (z[i] == n - i)
            ++occurence[z[i]];
    }
    for (int i = 0; i < n; ++i) {
        if (z[i] != n - i) {
            auto p = occurence.upper_bound(z[i]);
            if (p != occurence.begin()) {
                ++prev(p)->second;
                debug(prev(p)->first, prev(p)->second);
            }
        }
    }
    for (auto it = occurence.rbegin(); it != occurence.rend(); ++it) {
        if (next(it) != occurence.rend()) {
            next(it)->second += it->second;
        }
    }
    cout << occurence.size() << '\n';
    for (auto [length, count] : occurence) {
        cout << length << ' ' << count << '\n';
    }
    return;
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
