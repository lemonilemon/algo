/*
 * Created : 2025-02-28 22:41:40 lemonilemon
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
const int MAXN = 5e5 + 5;
bool avail[MAXN];
vector<int> ans;
// constants
void init() {
    ans.resize(5e5 + 5);
    iota(ans.begin(), ans.end(), 1);
    for (int i = 1; i < 5e5 + 5; i++) {
        avail[i] = true;
        ll sum = 1LL * i * (i + 1) / 2;
        ll sq = sqrtl(sum);
        if (sq * sq == sum) {
            avail[i] = false;
            swap(ans[i - 1], ans[i]);
        }
    }
}
// solution
void solve() {
    int n;
    cin >> n;
    if (!avail[n]) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
