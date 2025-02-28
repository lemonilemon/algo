/*
 * Created : 2025-02-18 23:38:13 lemonilemon
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
int cnt[26];
int presum[26][MAXN];
bool check(const string &s, int x) {
    bool flag = true;
    for (int i = 0; i < 26; ++i) {
        if (2 * presum[i][s.size() - x] > cnt[i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        return 1;
    flag = true;
    for (int i = 0; i < 26; ++i) {
        if (2 * (cnt[i] - presum[i][x]) > cnt[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}
// solution
void solve() {
    for (int i = 0; i < 26; ++i) {
        cnt[i] = 0;
    }
    string s;
    cin >> s;
    int k1 = 0;
    for (; k1 < ((int)s.size() >> 1); ++k1) {
        if (s[k1] != s[s.size() - k1 - 1])
            break;
    }
    string t;
    for (int i = k1; i < s.size() - k1; ++i) {
        t.push_back(s[i]);
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <= t.size(); ++j) {
            presum[i][j] = 0;
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < t.size(); ++j) {
            presum[i][j + 1] = presum[i][j];
            if (t[j] == 'a' + i) {
                ++presum[i][j + 1];
            }
        }
    }
    {
        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (2 * presum[i][t.size() >> 1] > cnt[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int k2 = 0;
            for (; k2 < ((int)t.size() >> 1); ++k2) {
                int mid = t.size() >> 1;
                if (t[mid + k2] != t[mid - k2 - 1])
                    break;
            }
            cout << ((int)t.size() >> 1) - k2 << '\n';
            return;
        }
    }
    int l = t.size() >> 1, r = t.size() + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(t, mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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
