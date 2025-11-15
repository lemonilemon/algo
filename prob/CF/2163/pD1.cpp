/*
 * Created : 2025-11-11 00:18:48 lemonilemon
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
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
void guess(int x) { cout << "! " << x << endl; }
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    bool left_zero = ask(1, n >> 1) > 0;
    sort(queries.begin(), queries.end(), [](auto a, auto b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    int largest_qr = -1;
    int ans = 0;
    for (auto [ql, qr] : queries) {
        if (largest_qr >= qr) {
            continue;
        }
        largest_qr = qr;

        if ((left_zero && ql <= (n >> 1)) || (!left_zero && ql > (n >> 1))) {
            int val = ask(ql, qr);
            ans = max(val, ans);
        }
    }
    guess(ans);
}

// main
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
