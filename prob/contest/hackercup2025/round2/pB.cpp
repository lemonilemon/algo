/*
 * Created : 2025-11-16 02:12:42 lemonilemon
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
vector<int> a;
vector<int> b;
int n, m;
const int MAXA = 1e6 + 5;

bool check(int x) {
    int mn_score = a[n - x];
    vector<int> score_freq(MAXA, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] < mn_score)
            continue;
        ++score_freq[a[i]];
    }
    queue<int> que;
    for (int i = 0; i < m; ++i) {
        que.push(b[i]);
    }
    vector<int> rank_freq; // freq with rank i+1
    for (int score = 0; score < MAXA; ++score) {
        if (score_freq[score] == 0)
            continue;
        rank_freq.push_back(score_freq[score]);
    }
    ll free_units = 0;
    int minus_units = 0;
    if (que.size() < rank_freq.size()) {
        return false;
    }
    for (int i = rank_freq.size(); i >= 0; --i) {
        while (que.size() > i) {
            int cnt = que.front();
            que.pop();
            if (cnt + free_units < minus_units) {
                return false;
            }
            cnt += free_units;
            free_units = 0;
            cnt -= minus_units;
            free_units += cnt;
        }
        int freq = i > 0 ? rank_freq[i - 1] : 0;
        minus_units += freq;
    }
    return true;
}
// solution
void solve() {
    cin >> n >> m;
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        debug(mid, check(mid));
        if (check(mid)) {
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
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
