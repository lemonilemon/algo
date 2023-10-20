/* 
 * Created : 2023-10-05 16:48:15 lemonilemon
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
const int MAXN = 1e5 + 5;
vector<ll> neg, pos;
int n;
ll k;
bool check(ll x) {
    ll cnt = 0; // greater or equal than x
    if(x >= 0) {
        safe();
        for(int i = pos.size() - 1, j = 0; i >= 0; --i) {
            while(j < i && pos[i] * pos[j] < x) ++j;
            if(i == j) break;
            cnt += i - j;
        }
        for(int i = neg.size() - 1, j = 0; i >= 0; --i) {
            while(j < i && neg[i] * neg[j] < x) ++j;
            if(i == j) break;
            cnt += i - j;
        }
    } else {
        x = -x; 
        cnt += (1ll * (pos.size()) * (pos.size() - 1) + 1ll * (neg.size()) * (neg.size() - 1)) >> 1;
        for(int i = pos.size() - 1, j = 0; i >= 0; --i) {
            while(j < neg.size() && pos[i] * neg[j] <= x) ++j;
            cnt += j;
        } 
    }
    debug(x, cnt);
    return cnt >= k;
}
// solution
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(a >= 0) pos.push_back(a);
        else neg.push_back(-a);
    }
    sort(pos.begin(), pos.end()); 
    sort(neg.begin(), neg.end()); 
    ll l = -(1e8 + 7), r = (1e8 + 7);
    while(r - l > 1) {
        ll mid = (l + r) >> 1; 
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
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

