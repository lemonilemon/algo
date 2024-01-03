/* 
 * Created : 2023-12-30 15:58:01 lemonilemon
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
vector<ll> ans;
void init() {
    map<multiset<int>, vector<ll> > mp;
    for(int i = 100000; i <= 300000; ++i) {
        multiset<int> s;
        ll x = 1ll * i * i;
        while(x) {
            s.insert(x % 10);
            x /= 10;
        }
        mp[s].push_back(1ll * i * i);
        if(mp[s].size() >= 99) {
            ans = mp[s];
            return;
        }
    }
}
// solution
void solve() {
    int n;
    cin >> n;
    if(n >= 11) {
        for(int k = 0; k < n; ++k) {
            cout << 1ll * ans[k];
            for(int i = 0; i < n - 11; ++i) {
                cout << '0';
            }
            cout << '\n';
        }
        return;
    }
    map<multiset<int>, vector<ll> > mp;
    int t = 1;
    int temp = n / 2;
    while(temp--) t *= 10; 
    debug(t);
    for(int i = t; i <= t * 10; ++i) {
        ll x = 1ll * i * i;
        multiset<int> s;
        while(x) {
            s.insert(x % 10);
            x /= 10;
        }
        mp[s].push_back(1ll * i * i);
        if(mp[s].size() == n) {
            for(auto a : mp[s]) {
                cout << a << '\n';
            }
            return;
        }
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

