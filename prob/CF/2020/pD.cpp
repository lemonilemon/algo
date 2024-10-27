/* 
 * Created : 2024-09-30 00:39:12 lemonilemon
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
vector<pair<int, int> > range[11][11]; // mod d = a
struct DSU {
    int n;
    int rk[MAXN], rt[MAXN]; 
    int cnt;
    void init(int _n) {
        n = _n;
        cnt = _n;
        for(int i = 0; i <= n; ++i) {
            rt[i] = i;
            rk[i] = 1;
        }
    }
    int findroot(int k) {
        return rt[k] == k ? k : rt[k] = findroot(rt[k]);
    }
    void setunion(int k1, int k2) {
        int r1 = findroot(k1);
        int r2 = findroot(k2);
        if(r1 == r2) return;
        --cnt;
        if(rk[r1] > rk[r2]) swap(r1, r2);
        rk[r2] += rk[r1];
        rt[r1] = r2;
    }
} dsu;
// solution
void solve() {
    int n, m; 
    cin >> n >> m;
    dsu.init(n);
    for(int i = 0; i < m; ++i) {
        int a, d, k;
        cin >> a >> d >> k;
        int id = a % d;
        int st = a / d;
        int ed = st + k;
        range[d][id].push_back({st, ed});
    }
    for(int d = 1; d <= 10; ++d) {
        for(int id = 0; id < d; ++id) {
            if(range[d][id].empty()) continue;
            sort(range[d][id].begin(), range[d][id].end());           
            vector<pair<int, int> > compressed;
            compressed.push_back(range[d][id][0]);
            for(int i = 1; i < range[d][id].size(); ++i) {
                if(range[d][id][i].first <= compressed.back().second) {
                    compressed.back().second = max(compressed.back().second, range[d][id][i].second);
                } else {
                    compressed.push_back(range[d][id][i]);
                }
            }
            for(auto [l, r] : compressed) {
                int lpos = id + l * d;
                for(int i = l + 1; i <= r; ++i) {
                    int pos = id + i * d;
                    dsu.setunion(pos, lpos);
                }
            }
            range[d][id].clear();
        }
    }
    cout << dsu.cnt << '\n';

}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

