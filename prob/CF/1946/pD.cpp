/* 
 * Created : 2024-03-22 23:47:12 lemonilemon
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
const int MAXN = 1e5 + 5;
int cnt[31];
int l[31], r[31];
int dif[MAXN];


int count(int n) {
    int cur = 0, ret = 0;
    for(int i = 1; i < n; ++i) {
        cur += dif[i];
        ret += (bool)(cur > 0);
    }
    return n - ret;
}
// solution
void solve() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < 31; ++i) {
        cnt[i] = 0;
        l[i] = n;
        r[i] = 0;
    }
    int xorsum = 0;
    for(int i = 1; i <= n; ++i) {
        dif[i] = 0;
        int a;
        cin >> a;
        xorsum ^= a;
        for(int j = 0; j < 31; ++j) {
            bool val = (a >> j) & 1;
            cnt[j] += val;
            if(val) {
                l[j] = min(l[j], i);
                r[j] = max(r[j], i);
            }
        }
    }
    if(xorsum > x) {
        cout << "-1\n";
        return;
    }
    int mxk = 1;
    for(int i = 30; i >= 0; --i) {
        bool check = (x >> i) & 1;
        if(check) {
            if(!cnt[i]) break; 
            if(cnt[i] & 1) continue;
            ++dif[l[i]], --dif[r[i]];
            mxk = max(mxk, count(n));
            --dif[l[i]], ++dif[r[i]];
        } else {
            if(!cnt[i]) continue;
            if(cnt[i] & 1) {
                cout << mxk << '\n';
                return;
            }
            ++dif[l[i]], --dif[r[i]];
        }
    }
    mxk = max(mxk, count(n));
    cout << mxk << '\n';
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

