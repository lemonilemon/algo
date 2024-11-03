/* 
 * Created : 2024-10-20 01:17:45 lemonilemon
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

map<int, ll> f[9][10];
int now[19]; 
ll p10[19];

ll dfs(int k, int d, int lst, ll m, ll mod, bool lim) {
    if(!d) return mod == 0;
    if(!lim && d <= k && f[d][lst].count(mod)) return f[d][lst][mod];
    ll cnt = 0;
    if(d > k + 1) {
        int r = lim? now[d - 1] : 9;
        int l = lst;
        for(int i = l; i <= r; ++i) {
            cnt += dfs(k, d - 1, i, m, (mod + i * p10[d - 1]) % m, lim && i == r);
        }
    } else if(d <= k) {
        int r = lim? min(now[d - 1], lst) : lst;
        int l = 1;
        for(int i = l; i <= r; ++i) {
            cnt += dfs(k, d - 1, i, m, (mod + i * p10[d - 1]) % m, lim && i == now[d - 1]);
        }
    } else {
        int r = lim? now[d - 1] : 9;
        int l = lst + 1;
        for(int i = l; i <= r; ++i) {
            cnt += dfs(k, d - 1, i - 1, m, (mod + i * p10[d - 1]) % m, lim && i == r);
        }
    }
    if(d <= k && !lim) f[d][lst][mod] = cnt;
    return cnt;
}

ll gans(ll a, ll m) {
    if(a < 0) return 0;
    p10[0] = 1 % m;
    for(int i = 1; i <= 18; ++i) {
        p10[i] = p10[i - 1] * 10 % m;
    }
    int len = 0;
    while(a) {
        now[len++] = a % 10;
        a /= 10;
    }
    ll ans = 0;
    for(int k = 0; 2 * k + 1 <= len; ++k) {
        for(int d = 0; d <= k; ++d) {
            for(int i = 0; i <= 9; ++i) {
                f[d][i].clear();
            }
        }
        ans += dfs(k, 2 * k + 1, k != 0, m, 0, 2 * k + 1 == len);
    }
    return ans;
}


// solution
void solve() {
    ll a, b; 
    ll m;
    cin >> a >> b >> m;
    cout << gans(b, m) - gans(a - 1, m) << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

