/* 
 * Created : 2024-07-26 23:54:48 lemonilemon
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
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
int a[MAXN];
map<int, vector<pair<int, int> > > queries;
int ans[MAXM];
map<int, int> lastpos;
int BIT[MAXN];

void modify(int val, int k) {
    for(; k < MAXN; k += k & -k) {
        BIT[k] ^= val;
    }
}
int query(int k) {
    int ret = 0;
    for(; k; k -= k & -k) {
        ret ^= BIT[k];
    }
    return ret;
}

// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; 
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back(make_pair(l, i));
    }
    for(int r = 1; r <= n; ++r) {
        modify(a[r], r);
        if(lastpos.count(a[r])) modify(a[r], lastpos[a[r]]);
        lastpos[a[r]] = r;
        modify(a[r], lastpos[a[r]]); 
        for(auto [l, idx] : queries[r]) {
            ans[idx] = query(r) ^ query(l - 1);
        }
    }
    for(int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }

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

