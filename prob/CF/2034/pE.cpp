/*
 * Created : 2024-12-01 00:46:39 lemonilemon
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
int fact[11];
void init() {
    fact[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    if (n <= 10 && k > fact[n]) {
        cout << "NO\n";
        return;
    }
    if (k == 1) {
        if (n == 1) {
            cout << "YES\n";
            cout << "1\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (!(n & 1) && (k & 1)) {
        cout << "NO\n";
        return;
    }
    if (n <= 10 && fact[n] - 1 == k) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> ans;
    if (!(k & 1)) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        do {
            if (ans.size() == k)
                break;
            auto b = p;
            for (auto &x : b) {
                x = n - x + 1;
            }
            ans.push_back(p);
            ans.push_back(b);
        } while (next_permutation(p.begin(), p.end()));
    } else {
        ans.resize(3);
        for (int i = 0; i < n; ++i) {
            ans[0].push_back(i + 1);
        }
        for (int i = 0; i < n; ++i) {
            ans[1].push_back((i + n / 2) % n + 1);
        }
        for (int i = 0; i < n; ++i) {
            ans[2].push_back((n - 2 * i - 1 + 2 * n) % n + 1);
        }
        {
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            do {
                if (ans.size() == k)
                    break;
                auto b = p;
                for (auto &x : b) {
                    x = n - x + 1;
                }
                if (b == ans[0] || p == ans[0] || b == ans[1] || p == ans[1] ||
                    b == ans[2] || p == ans[2])
                    continue;
                ans.push_back(p);
                ans.push_back(b);
            } while (next_permutation(p.begin(), p.end()));
        }
    }
    if (ans.size() != k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto p : ans) {
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
    return;
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
