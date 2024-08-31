/* 
 * Created : 2024-08-31 21:01:52 lemonilemon
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
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0) 
#define safe() ((void)0) 
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 2e5 + 5;
vector<int> cs[MAXN];
int r[MAXN], c[MAXN];

// solution
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i) {
        cs[i].clear();
    }
    vector<int> rvals;
    for(int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i];
        rvals.push_back(r[i]);
    }
    sort(rvals.begin(), rvals.end());
    rvals.erase(unique(rvals.begin(), rvals.end()), rvals.end());
    for(int i = 0; i < n; ++i) {
        r[i] = lower_bound(rvals.begin(), rvals.end(), r[i]) - rvals.begin();
        debug(i, r[i], c[i]);
        cs[r[i]].push_back(c[i]);
    }
    vector<int> lis;
    vector<int> rows;
    map<pair<int, int>, pair<int, int> > backtrack;
    for(int i = 0; i < n; ++i) {
        sort(cs[i].begin(), cs[i].end());
        for(auto col : cs[i]) {
            if(lis.empty() || col >= lis.back()) {
                if(lis.empty()) {
                    backtrack[{rvals[i], col}] = {1, 1};
                } else  {
                    backtrack[{rvals[i], col}] = {rows.back(), lis.back()};
                    debug(rvals[i], col, rows.back(), lis.back()); 
                }
                lis.push_back(col);
                rows.push_back(rvals[i]);
                continue;
            } 
            auto idx = upper_bound(lis.begin(), lis.end(), col) - lis.begin();
            lis[idx] = col;
            rows[idx] = rvals[i];
            if(idx) {
                backtrack[{rvals[i], col}] = {rows[idx - 1], lis[idx - 1]};
            } else {
                backtrack[{rvals[i], col}] = {1, 1};
            }
        }
    }
    cout << lis.size() << '\n';
    int curr = rows.back(), curc = lis.back();
    vector<pair<int, int> > ans;
    ans.push_back({h, w});
    while(curr > 1 || curc > 1) {
        ans.push_back({curr, curc});
        auto p = backtrack[{curr, curc}];
        curr = p.first;
        curc = p.second;
    }
    ans.push_back({1, 1});
    reverse(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); ++i) {
        debug(i, ans[i].first, ans[i].second);
        for(int j = 0; j < ans[i].first - ans[i - 1].first; ++j) 
            cout << 'D';
        for(int j = 0; j < ans[i].second - ans[i - 1].second; ++j) 
            cout << 'R';
    }
    cout << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

