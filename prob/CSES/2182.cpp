#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
#define safe() std::cerr << "\033[1;32m" << __PRETTY_FUNCTION__ << " is safe\033[0m\n"
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
FILE* setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int x[MAXN], k[MAXN];
int mabs(ll a, int mod = MOD) {
	return (a % mod + mod) % mod;
}
int madd(int a, int b, int mod = MOD) {
	return mabs(a + b, mod);
}
int mmul(int a, int b, int mod = MOD) {
	return mabs(1ll * a * b, mod);
}
int fastpow(int a, int b, int mod = MOD) {
	a = mabs(a, mod);
	int ret = 1;
	while(b) {
		if(b & 1) ret = mmul(ret, a, mod);
		a = mmul(a, a, mod);
		b >>= 1;
	}
	return ret;
}
int inv(ll a, int mod = MOD) {
	a = mabs(a);
	return fastpow(a, mod - 2);
}
int seg[MAXN << 2];
void pull(int v) {
    seg[v] = mmul(seg[v << 1], seg[v << 1 | 1], MOD - 1);
}
void build(int l, int r, int v) {
    if(l == r) {
        seg[v] = mabs(k[l] + 1, MOD - 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
int query(int ql, int qr, int l, int r, int v) {
    if(ql > qr) return 1;
    if(ql == l && qr == r) return seg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    return mmul(query(ql, mid, l, mid, v << 1), query(mid + 1, qr, mid + 1, r, v << 1 | 1), MOD - 1);
}
void solve() {
	int n;
	cin >> n;
	int ans[3]{};
	int val = 1;
	ans[0] = ans[1] = ans[2] = 1;
    int cnt = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i] >> k[i];
		ans[0] = mmul(ans[0], k[i] + 1);
        ans[1] = mmul(ans[1], mmul(fastpow(x[i], k[i] + 1) - 1, inv(x[i] - 1)));
	}
    build(1, n, 1);
    for(int i = 1; i <= n; ++i) {
        int cnt = mabs(1ll * k[i] * (k[i] + 1) >> 1, MOD - 1);    
        int mul = mmul(query(1, i - 1, 1, n, 1), query(i + 1, n, 1, n, 1), MOD - 1);
        ans[2] = mmul(ans[2], fastpow(x[i], mmul(mul, cnt, MOD - 1)));
    }
	for(int i = 0; i < 3; ++i) {
		cout << ans[i] << " \n"[i == 2];
	}
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

