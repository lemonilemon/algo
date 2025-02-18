/*
 * Created : 2024-11-15 01:03:21 lemonilemon
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
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
struct fraction {
    ll n, d;
    fraction(const ll &_n = 0, const ll &_d = 1) : n(_n), d(_d) {
        ll t = __gcd(n, d);
        n /= t, d /= t;
        if (d < 0)
            n = -n, d = -d;
    }
    fraction operator-() const { return fraction(-n, d); }
    fraction operator+(const fraction &b) const {
        return fraction(n * b.d + b.n * d, d * b.d);
    }
    fraction operator-(const fraction &b) const {
        return fraction(n * b.d - b.n * d, d * b.d);
    }
    fraction operator*(const fraction &b) const {
        return fraction(n * b.n, d * b.d);
    }
    fraction operator/(const fraction &b) const {
        return fraction(n * b.d, d * b.n);
    }
    void print() {
        cout << n;
        if (d != 1)
            cout << "/" << d;
    }
};

const int N = 505;
const int mod = 998244353;
ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
struct ModInt {
    ll val;
    ModInt(ll _val = 0) : val((_val % mod + mod) % mod) {}
    ModInt operator-() const { return (mod - val) % mod; }
    ModInt operator+(const ModInt &b) const { return (val + b.val) % mod; }
    ModInt operator-(const ModInt &b) const {
        return (val - b.val + mod) % mod;
    }
    ModInt operator*(const ModInt &b) const { return val * b.val % mod; }
    ModInt operator/(const ModInt &b) const {
        return (val * fpow(b.val, mod - 2)) % mod;
    }
};
struct matrix { // m variables, n equations
    int n, m;
    ModInt A[N][N + 1], sol[N];
    vector<int> pivots, free;
    vector<vector<ModInt>> basis;
    int solve() { //-1: inconsistent, >= 0: rank
        for (int i = 0; i < n; ++i) {
            int piv = 0;
            while (piv < m && !A[i][piv].val)
                ++piv;
            if (piv == m)
                continue;
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                ModInt tmp = -A[j][piv] / A[i][piv];
                for (int k = 0; k <= m; ++k)
                    A[j][k] = tmp * A[i][k] + A[j][k];
            }
        }
        int rank = 0;
        for (int i = 0; i < n; ++i) {
            int piv = 0;
            while (piv < m && !A[i][piv].val)
                ++piv;
            if (piv == m && A[i][m].val)
                return -1;
            else if (piv < m)
                pivots.push_back(piv), ++rank, sol[piv] = A[i][m] / A[i][piv];
        }
        // for basis
        for (int i = 0, j = 0; i < m; ++i) {
            if (j < pivots.size() && i == pivots[j]) {
                ++j;
                continue;
            } else
                free.push_back(i);
        }
        for (auto f : free) {
            basis.push_back(vector<ModInt>(m, 0));
            basis.back()[f] = 1;
            for (int i = 0; i < n; ++i) {
                int piv = 0;
                while (piv < m && !A[i][piv].val)
                    ++piv;
                if (piv == m)
                    continue;
                basis.back()[piv] = -A[i][f] / A[i][piv];
            }
        }
        return rank;
    }
};
// solution
void solve() {
    matrix gauss;
    cin >> gauss.n >> gauss.m;
    int n = gauss.n, m = gauss.m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll val;
            cin >> val;
            gauss.A[i][j] = ModInt(val);
        }
    }
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        gauss.A[i][m] = ModInt(val);
    }
    int rank = gauss.solve();
    if (rank == -1) {
        cout << -1 << '\n';
        return;
    }
    int R = m - rank;
    cout << R << '\n';
    for (int i = 0; i < m; ++i) {
        cout << gauss.sol[i].val << " \n"[i == m - 1];
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << gauss.basis[i][j].val << " \n"[j == m - 1];
        }
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
