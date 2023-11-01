/* 
 * Created : 2023-10-05 15:52:46 lemonilemon
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
const int MOD = 998244353;
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
int mmul(int a, int b) {
    return mabs(1ll * a * b);
}
int** mmul(int** a, int** b) {
    int** ret;
    ret = new int*[2];
    for(int i = 0; i < 2; ++i) {
        ret[i] = new int[2];
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            ret[i][j] = 0;
            for(int k = 0; k < 2; ++k) {
                ret[i][j] = madd(ret[i][j], mmul(a[i][k], b[k][j]));
            }
        }
    }
    return ret;
}
int** fastpow(int** a, int b) {
    int** ret;
    ret = new int*[2];
    for(int i = 0; i < 2; ++i) {
        ret[i] = new int[2];
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(i == j) ret[i][j] = 1;
            else ret[i][j] = 0;
        }
    }
    while(b) {
        if(b & 1) ret = mmul(ret, a);
        b >>= 1;
        a = mmul(a, a);
    }
    return ret;
}
int** T, A[2];
// solution
void solve() {
    T = new int*[2];
    for(int i = 0; i < 2; ++i) {
        T[i] = new int[2];
    }
    int a, b, n;
    cin >> A[1] >> A[0] >> T[0][0] >> T[0][1] >> n;
    if(n == 1) {
        cout << A[1] << '\n';
        return;
    }
    T[1][0] = 1;
    T[1][1] = 0;
    auto k = fastpow(T, n - 2);
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            debug(i, j, k[i][j]);
        }
    }
    cout << madd(mmul(k[0][0], A[0]), mmul(k[0][1], A[1])) << '\n'; 
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

