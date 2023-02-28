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
const int MAXN = 2e5 + 5;
const ll INF = 1e18 + 9;
ll a[MAXN];
ll presum[MAXN];
void solve() {
	ll n, k, x;
	cin >> n >> k >> x;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		presum[i] = presum[i - 1] + a[i];
	}
	if(x > 0) {
		ll ans = 0;
		ll mx = -INF;
		for(ll r = 1; r <= n; ++r) {
			if(r - k + 1 > 0) mx = max(-presum[r - k] + 1ll * x * (k + r), mx);	
			ans = max(ans, presum[r] + mx - 1ll * r * x);
			for(ll l = max(1ll, r - k + 1); l <= r; ++l) {
				ll buf = presum[r] - presum[l - 1] + 1ll * x * (r - l + 1);
				ans = max(ans, buf);
			}
		}
		cout << ans << '\n';
	} else {
		ll ans = 0;
		ll mx = -INF;
		for(ll r = n; r > 0; --r) {
			if(r + k - n - 1 <= n) mx = max(-presum[r - k] + 1ll * x * (k + r), mx);	
			ans = max(ans, presum[r] + mx - 1ll * r * x);
			for(ll l = max(1ll, r - k + 1); l <= r; ++l) {
				ll buf = presum[r] - presum[l - 1] + 1ll * x * (r - l + 1);
				ans = max(ans, buf);
			}
		}
	}
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

