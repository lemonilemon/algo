/* 
 * Created : 2023-09-25 23:35:59 lemonilemon
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
#endif

// constants
const int MAXN = 2505;
vector<int> ans[2];
int a[MAXN], tmp[MAXN];
int n[2];
void choose(int p, int t) {
    ans[t].push_back(p);
    int cnt = 0;
    for(int i = p + 1; i <= n[t]; ++i) {
        tmp[++cnt] = a[i];
    }
    tmp[++cnt] = a[p];
    for(int i = 1; i < p; ++i) {
        tmp[++cnt] = a[i];
    }
    for(int i = 1; i <= n[t]; ++i) {
        a[i] = tmp[i];
    }
}
// solution
void solve() {
    cin >> n[0] >> n[1];
    for(int t = 0; t < 2; ++t) {
        debug(t);
        for(int i = 1; i <= n[t]; ++i) {
            cin >> a[i];
        }
        for(int i = 1; i <= n[t]; ++i) {
            for(int j = 1; j <= n[t]; ++j) {
                if(a[j] == i) {
                    choose(j, t);
                    break;
                }
            }
            for(int j = 1; j < n[t]; ++j) {
                if(a[j] == i) {
                    choose(j + 1, t);
                    break;
                }
            }
        }
    }
    if((ans[0].size() & 1) ^ (ans[1].size() & 1)) {
        if(!(n[0] & 1) && !(n[1] & 1)) {
            cout << "-1\n";
            return;
        }
        if(n[0] & 1) for(int i = 0; i < n[0]; ++i) ans[0].push_back(1);
        else for(int i = 0; i < n[1]; ++i) ans[1].push_back(1); 
    }
    while(ans[0].size() > ans[1].size()) {
        ans[1].push_back(1);
        ans[1].push_back(n[1]);
    }
    while(ans[1].size() > ans[0].size()) {
        ans[0].push_back(1);
        ans[0].push_back(n[0]);
    }
    cout << ans[0].size() << '\n';
    for(int i = 0; i < ans[0].size(); ++i) {
        cout << ans[0][i] << ' ' << ans[1][i] << '\n';
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

