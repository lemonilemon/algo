/*
 * Created : 2024-12-03 14:30:15 lemonilemon
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
int ord[MAXN];
pair<int, int> bit[MAXN];
void modify(int k, int val, int idx) {
    for (; k <= n; k += k & -k) {
        bit[k] = min(bit[k], {val, idx});
    }
}
pair<int, int> query(int k) {
    pair<int, int> ret = {1e9 + 7, 1e9 + 7};
    for (; k > 0; k -= k & -k)
        ret = min(ret, bit[k]);
    return ret;
}
// solution
void f(int l, int r) {
    if (l == r)
        return;
    int mnidx = l;
    for (int i = l; i <= r; ++i) {
        if (a[i] < a[mnidx])
            mnidx = i;
    }
    deque<int> left;
    for (int i = l; i < mnidx; ++i) {
        left.push_back(a[i] + 1);
    }
    sort(left.begin(), left.end());
    if (mnidx != r)
        f(mnidx + 1, r);
    deque<int> right;
    for (int i = mnidx + 1; i <= r; ++i) {
        int val = a[i];
        if (!left.empty() && left.front() < val)
            ++val;
        right.push_back(val);
    }
    a[l] = a[mnidx];
    for (int i = l + 1; i <= r; ++i) {
        if (left.empty()) {
            a[i] = right.front();
            right.pop_front();
            continue;
        }
        if (right.empty()) {
            a[i] = left.front();
            left.pop_front();
            continue;
        }
        if (left.front() < right.front()) {
            a[i] = left.front();
            left.pop_front();
        } else {
            a[i] = right.front();
            right.pop_front();
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        bit[i] = {1e9 + 7, 1e9 + 7};
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        modify(n - i + 1, a[i], i);
    }
    int mnidx = 0;
    int mnleft = 1e9 + 7;
    deque<int> left;
    deque<int> right;
    while (mnidx < n) {
        // debug(mnidx);
        auto [nxtval, nxtidx] = query(n - mnidx);
        for (int i = mnidx + 1; i < nxtidx; ++i) {
            left.push_back(a[i] + 1);
            mnleft = min(mnleft, a[i] + 1);
        }
        right.push_back(a[nxtidx] + (mnleft < a[nxtidx]));
        mnidx = nxtidx;
    }
    sort(left.begin(), left.end());
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (left.empty()) {
            cout << right.front();
            right.pop_front();
        } else if (right.empty()) {
            cout << left.front();
            left.pop_front();
        } else if (left.front() < right.front()) {
            cout << left.front();
            left.pop_front();
        } else {
            cout << right.front();
            right.pop_front();
        }
        cout << " \n"[i == n - 1];
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
