/*
 * Created : 2024-12-03 15:37:31 lemonilemon
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
vector<pair<int, int>> ps;
int bit[2][MAXN << 1];
int n;
void modify(int id, int k, int val) {
    for (; k <= n; k += k & -k) {
        bit[id][k] += val;
    }
}
int binsearch(int id, int val) {
    if (val <= 0)
        return 0;
    int res = 0;
    for (int i = __lg(n); i >= 0; --i) {
        if (bit[id][res + (1 << i)] < val) {
            val -= bit[id][res + (1 << i)];
            res += 1 << i;
        }
    }
    return res + 1;
}
int query(int id, int k) {
    int res = 0;
    for (; k > 0; k -= k & -k) {
        res += bit[id][k];
    }
    return res;
}
// solution
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        bit[0][i] = bit[1][i] = 0;
    }
    ps.clear();
    ps.resize(n);
    vector<int> xvals;
    vector<int> yvals;
    for (auto &[x, y] : ps) {
        cin >> x >> y;
        xvals.push_back(x);
        yvals.push_back(y);
    }
    sort(begin(xvals), end(xvals));
    sort(begin(yvals), end(yvals));
    xvals.erase(unique(begin(xvals), end(xvals)), end(xvals));
    yvals.erase(unique(begin(yvals), end(yvals)), end(yvals));
    map<int, vector<int>> ys;
    for (auto &[x, y] : ps) {
        x = lower_bound(begin(xvals), end(xvals), x) - begin(xvals) + 1;
        y = lower_bound(begin(yvals), end(yvals), y) - begin(yvals) + 1;
        ys[x].push_back(y);
    }

    int leftsum = 0;
    int rightsum = n;
    for (auto [x, y] : ps) {
        modify(1, y, 1);
    }
    int ans = 0;
    int ansx = 0, ansy = 0;
    int curval = 0;
    for (auto [x0, yss] : ys) {
        leftsum += yss.size();
        rightsum -= yss.size();
        for (auto y : yss) {
            modify(0, y, 1);
            modify(1, y, -1);
        }
        for (int val = curval + (int)yss.size();
             val >= curval - (int)yss.size(); --val) {
            int lowleft, lowright, highleft, highright;
            lowleft = binsearch(0, val);
            lowright = binsearch(1, val);
            highleft = binsearch(0, leftsum - val + 1) - 1;
            highright = binsearch(1, rightsum - val + 1) - 1;
            // debug(xvals[x0 - 1], val, lowleft, lowright, highleft,
            // highright);
            if (max(lowleft, lowright) > min(highleft, highright))
                continue;
            int y0 = max(lowleft, lowright);
            if (val > ans) {
                ans = val;
                ansx = xvals[x0 - 1];
                ansy = yvals[y0 - 1];
            }
            curval = val;
            break;
        }
    }
    cout << ans << '\n';
    cout << ansx << ' ' << ansy << '\n';
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
