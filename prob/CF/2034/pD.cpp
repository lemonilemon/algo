/*
 * Created : 2024-11-30 23:20:55 lemonilemon
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
const int MAXN = 2e5 + 5;
int a[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    priority_queue<int> zeros;
    priority_queue<int, vector<int>, greater<int>> twos;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ++cnt0;
            zeros.push(i);
        } else if (a[i] == 1) {
            ++cnt1;
            s.insert(i);
        } else {
            ++cnt2;
            twos.push(i);
        }
    }
    vector<pair<int, int>> ans;
    for (int k = 1; k <= n; ++k) {
        bool flag = 0;
        while (!twos.empty() && twos.top() < *s.rbegin()) {
            int i = twos.top();
            twos.pop();
            flag = 1;
            ans.push_back({i, *s.rbegin()});
            swap(a[i], a[*s.rbegin()]);
            twos.push(*s.rbegin());
            s.insert(i);
            s.erase(*s.rbegin());
        }
        while (!zeros.empty() && *s.begin() < zeros.top()) {
            int i = zeros.top();
            zeros.pop();
            flag = 1;
            ans.push_back({i, *s.begin()});
            zeros.push(*s.begin());
            swap(a[i], a[*s.begin()]);
            s.insert(i);
            s.erase(*s.begin());
        }
        if (!flag)
            break;
    }
    /*for (int i = 1; i <= n; ++i) {
        cerr << a[i] << " \n"[i == n];
    }*/
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
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
