/*
 * Created : 2025-08-24 22:46:09 lemonilemon
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
const int MAXN = 505;
int longest[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    int mxlen = 0;
    int st = -1;
    for (int i = 1; i <= n; ++i) {
        cout << "? " << i << ' ' << n;
        for (int j = 1; j <= n; ++j) {
            cout << ' ' << j;
        }
        cout << endl;
        cout.flush();
        int res;
        cin >> res;
        longest[i] = res;
        if (res > mxlen) {
            mxlen = res;
            st = i;
        }
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
        if (i == st)
            continue;
        cout << "? " << st << ' ' << s.size() - 1;
        for (auto x : s) {
            if (x == i)
                continue;
            cout << ' ' << x;
        }
        cout << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res == mxlen) {
            s.erase(i);
        }
    }
    for (auto x : s) {
        ans[(int)s.size() - longest[x]] = x;
    }
    cout << "! " << s.size();
    for (int i = 0; i < (int)s.size(); ++i) {
        cout << ' ' << ans[i];
    }
    cout << endl;
    cout.flush();
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
