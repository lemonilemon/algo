/* 
 * Created : 2023-09-22 10:19:03 lemonilemon
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
ll presum[MAXN];


// solution
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> stk, t;
    presum[0] = 0;
    stk.push_back(0);
    t.push_back(0);
    ll mn = n + 1;
    for(int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
        int pos = upper_bound(stk.begin(), stk.end(), presum[i] - k) - stk.begin();
        if(pos) {
            //debug(i, pos - 1, stk[pos - 1], t[pos - 1], presum[i] - stk[pos - 1]);
            mn = min(i - t[pos - 1], mn);
        }
        while(!stk.empty() && presum[i] <= stk.back()) {
            stk.pop_back();
            t.pop_back();
        }
        stk.push_back(presum[i]);
        t.push_back(i);
    }
    if(mn == n + 1) cout << "-1\n";
    else cout << mn << '\n';
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

