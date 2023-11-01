/* 
 * Created : 2023-10-20 10:39:29 lemonilemon
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
int x[MAXN];
vector<int> pos[MAXN];
int BIT[MAXN];
void modify(int k) {
    for(; k < MAXN; k += k & -k) ++BIT[k];
}
int query(int k) {
    int ret = 0;
    for(; k > 0; k ^= k & -k) ret += BIT[k];
    return ret;
}
bool color[MAXN];
// solution
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        pos[x[i]].push_back(i);
    }
    for(int i = 1; i <= k; ++i) {
        int j = pos[i].size() - 1;
        int mxval = query(pos[i][j]);
        while(j && query(pos[i][j - 1]) == mxval) --j;

        color[pos[i][j]] = 1;
        modify(pos[i][j]);
    }
    bool begin = 1;
    for(int i = 1; i <= n; ++i) {
        if(color[i]) {
            if(begin) begin = 0;
            else cout << ' ';
            cout << x[i];
        }
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

