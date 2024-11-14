/*
 * Created : 2024-11-13 13:20:05 lemonilemon
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
#define all(x) begin(x), end(x)
const int N = 5e5 + 5;
#define base ll // complex<double>
// const double PI = acosl(-1);
const ll mod = 998244353, g = 3;
base omega[4 * N], omega_[4 * N];
int rev[4 * N];
ll fpow(ll b, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1)
            ret = ret * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return ret;
}
ll inverse(ll a) { return fpow(a, mod - 2); }
void calcW(int n) {
    ll r = fpow(g, (mod - 1) / n), invr = inverse(r);
    omega[0] = omega_[0] = 1;
    for (int i = 1; i < n; i++) {
        omega[i] = omega[i - 1] * r % mod;
        omega_[i] = omega_[i - 1] * invr % mod;
    }
    // double arg = 2.0 * PI / n;
    // for (int i = 0; i < n; i++)
    // {
    // omega[i] = base(cos(i * arg), sin(i * arg));
    // omega_[i] = base(cos(-i * arg), sin(-i * arg));
    // }
}
void calcrev(int n) {
    int k = __lg(n);
    for (int i = 0; i < n; i++)
        rev[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
                rev[i] ^= 1 << (k - j - 1);
}
vector<base> NTT(vector<base> poly, bool inv) {
    base *w = (inv ? omega_ : omega);
    int n = (int)poly.size();
    for (int i = 0; i < n; i++)
        if (rev[i] > i)
            swap(poly[i], poly[rev[i]]);
    for (int len = 1; len < n; len <<= 1) {
        int arg = n / len / 2;
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                base odd = w[j * arg] * poly[i + j + len] % mod;
                poly[i + j + len] = (poly[i + j] - odd + mod) % mod;
                poly[i + j] = (poly[i + j] + odd) % mod;
            }
    }
    if (inv)
        for (auto &a : poly)
            a = a * inverse(n) % mod;
    return poly;
}
vector<base> mul(vector<base> f, vector<base> g) {
    int sz = 1 << (__lg(f.size() + g.size() - 1) + 1);
    f.resize(sz), g.resize(sz);
    calcrev(sz);
    calcW(sz);
    f = NTT(f, 0), g = NTT(g, 0);
    for (int i = 0; i < sz; i++)
        f[i] = f[i] * g[i] % mod;
    return NTT(f, 1);
}
#define poly vector<ll>
poly integrate(poly A) {
    poly B = {0};
    for (int i = 0; i < A.size(); ++i) {
        B.push_back(inverse(i + 1) * A[i] % mod);
    }
    return B;
}
poly derivative(poly A) {
    poly B;
    for (int i = 1; i < A.size(); ++i) {
        B.push_back(i * A[i] % mod);
    }
    B.push_back(0);
    return B;
}
poly inv(poly A) {
    A.resize(1 << (__lg(A.size() - 1) + 1));
    poly B = {inverse(A[0])};
    for (int n = 1; n < (int)A.size(); n <<= 1) {
        poly pA(A.begin(), A.begin() + 2 * n);
        calcrev(4 * n), calcW(4 * n);
        pA.resize(4 * n), B.resize(4 * n);
        pA = NTT(pA, 0);
        B = NTT(B, 0);
        for (int i = 0; i < 4 * n; i++)
            B[i] = ((B[i] * 2 - pA[i] * B[i] % mod * B[i]) % mod + mod) % mod;
        B = NTT(B, 1);
        B.resize(2 * n);
    }
    return B;
}
pair<poly, poly> div(poly A, poly B) {
    if (A.size() < B.size())
        return make_pair(poly(), A);
    int n = A.size(), m = B.size();
    poly revA = A, invrevB = B;
    reverse(all(revA)), reverse(all(invrevB));
    revA.resize(n - m + 1);
    invrevB.resize(n - m + 1);
    invrevB = inv(invrevB);
    poly Q = mul(revA, invrevB);
    Q.resize(n - m + 1);
    reverse(all(Q));
    poly R = mul(Q, B);
    R.resize(m - 1);
    for (int i = 0; i < m - 1; i++)
        R[i] = (A[i] - R[i] + mod) % mod;
    return make_pair(Q, R);
}
poly polyln(poly A) {
    poly B = mul(derivative(A), inv(A));
    B = integrate(B);
    return B;
}
poly polyexp(poly A) {
    A.resize(1 << (__lg((int)A.size() - 1) + 1));
    poly B = {1};
    for (int n = 1; n < (int)A.size(); n <<= 1) {
        poly pA(A.begin(), A.begin() + 2 * n);
        pA.resize(2 * n), B.resize(2 * n);
        poly lnB = polyln(B);
        lnB.resize(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            lnB[i] = ((pA[i] - lnB[i]) % mod + mod) % mod;
        }
        lnB[0] = (lnB[0] + 1) % mod;
        B = mul(B, lnB);
        B.resize(2 * n);
    }
    return B;
}

// solution
void solve() {
    int n;
    cin >> n;
    poly A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    poly B = polyexp(A);
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " \n"[i == n - 1];
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
