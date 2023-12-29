/* 
 * Created : 2023-12-09 16:28:45 lemonilemon
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

// solution
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a;
    for(int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    if(k > 2) {
        cout << "0\n";
        return;
    }
    ll mn = 4e18;
    vector<ll> b;
    for(int i = 0; i < n; ++i) {
        mn = min(mn, a[i]);
        for(int j = i + 1; j < n; ++j) {
            mn = min(mn, abs(a[i] - a[j]));
            b.push_back(abs(a[i] - a[j]));
        }
    }
    if(k == 2) {     
        sort(b.begin(), b.end());
        for(int i = 0; i < n; ++i) {
            auto p = lower_bound(b.begin(), b.end(), a[i]);
            if(p != b.end()) mn = min(mn, (*p - a[i]));
            if(p != b.begin()) mn = min(mn, (a[i] - *prev(p)));
        }
    }
    cout << mn << '\n';
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
