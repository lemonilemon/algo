#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int MAXN = 2e5 + 5, MAXM = 2e5 + 5;
ll a[MAXN], st[MAXN + MAXM];
ll cnt[MAXN + MAXM];
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n + m; ++i) {
		st[i] = 0;
		cnt[i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		st[a[i]] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		int p, v; 
		cin >> p >> v;
		debug(i), debug(p), debug(a[p]), debug(st[a[p]]);
		cnt[a[p]] += i - st[a[p]];
		a[p] = v;
		st[v] = i;
	}
	for(int i = 1; i <= n; ++i) {
		cnt[a[i]] += m + 1 - st[a[i]];
	}
	ll ans = n * (1ll * m * (m + 1) >> 1) << 1;
	debug(ans);
	for(int i = 1; i <= n + m; ++i) {
		if(cnt[i]) ans -= (cnt[i] * (cnt[i] - 1)) >> 1;	
	}
	cout << ans << '\n';
}

int main() {
	setIO();
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

