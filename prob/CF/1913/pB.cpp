/* 
 * Created : 2023-12-18 14:41:12 lemonilemon
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
int suf[MAXN];

bool check(int n, int k) {
    int ori1 = suf[0];
    int ori0 = n - ori1;
    int cnt1 = ori1 - suf[n - k];
    int cnt0 = (n - k) - cnt1;
    // debug(n, k, ori1, cnt1, ori0, cnt0);
    return ori1 >= cnt0 && ori0 >= cnt1;
}
// solution
void solve() {
    string s;
    cin >> s;
    suf[s.size()] = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + (s[i] == '1');
    }
    int l = -1, r = s.size();
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(check(s.size(), mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
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

