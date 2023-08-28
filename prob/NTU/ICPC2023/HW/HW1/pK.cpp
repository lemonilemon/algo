/* 
 * Created : 2023-08-14 15:11:40 lemonilemon
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
const int C = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MAXQ = 3e6 + 5;
// solution
int a[MAXN];
struct BIT {
    int sz;
    int* val;
    void init(int n) {
        sz = n;
        val = new int[sz + 1];
    }
    void modify(int k) {
        for(; k <= sz; k += k & -k) {
            ++val[k];
        }
    }
    int kth(int k) {
        int res = 0;
        for(int i = 1 << __lg(sz); i > 0; i >>= 1) {
            if(res + i <= sz && val[res + i] < k) k -= val[res += i];
        }
        return res + 1;
    }
};
BIT bit;
map<int, vector<int> > chunks[__lg(C) + 1];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int r = 1; r <= n; ++r) {
        if(r >= 3) {
            for(int i = 0; i <= __lg(C); ++i) {
                int idx = a[r] >> i;
                for(int j = -1; j <= 1; ++j) {
                    if(chunks[i].count(idx + j)) {
                        for(auto l : chunks[i][idx + j]) {
                            bit.modify(abs(a[r] - a[l]));
                        }
                    }
                }
            }
        }
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

