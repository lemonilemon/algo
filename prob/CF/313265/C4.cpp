/* 
 * Created : 2023-10-06 05:48:41 lemonilemon
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
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;
int s[MAXN];
int bit[MAXN];
int query(int k) {
    int ret = 0;
    for(; k > 0; k ^= k & -k) ret += bit[k];
    return ret;
}
void modify(int k) {
    for(; k < MAXN; k += k & -k) ++bit[k];
}
struct Quest {
    int a, b, num;
} quests;
int ans[MAXM];
vector<Quest> sub[MAXM], add[MAXM]; // quest[l]

// solution
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for(int i = 0; i < m; ++i) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        sub[l - 1].push_back({a, b, i});
        add[r].push_back({a, b, i});
    }
    for(int i = 1; i <= n; ++i) {
        modify(s[i]);
        for(auto [a, b, num] : sub[i]) {
            ans[num] -= query(b) - query(a - 1);
        }
        for(auto [a, b, num] : add[i]) {
            ans[num] += query(b) - query(a - 1);
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

