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
const int MAXN = 2e5 + 5;
const ll INF = 1e18 + 7;
void solve() {
	int n;
	cin >> n;
	vector<ll> a;
	for(int i = 0; i < n; ++i) {
		int buf;
		cin >> buf;
		a.push_back(buf);
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	//choose w1
	for(int i = 2; i < n; ++i) {
		//choose w2
		ll w2 = a[i];
		ll w1 = a[0];
		ll w3 = a[i - 1];
		ll mn = abs(w1 - w2) + abs(w2 - w3);
		ans = max(mn, ans);
	}
	for(int i = 0; i < n - 2; ++i) {
		//choose w2
		ll w2 = a[i];
		ll w3 = a[n - 1];
		ll w1 = a[i + 1];
		ll mn = abs(w1 - w2) + abs(w2 - w3);
		ans = max(mn, ans);
	}
	for(int i = 1; i < n - 2; ++i) {
		ll w1 = a[0];
		ll w3 = a[i];
		ll w2 = a[i + 1];
		ll mn = abs(w1 - w2) + abs(w2 - w3);
		ans = max(mn, ans);
	}
	for(int i = 2; i < n; ++i) {
		ll w1 = a[n - 1];
		ll w3 = a[i];
		ll w2 = a[i - 1];
		ll mn = abs(w1 - w2) + abs(w2 - w3);
		ans = max(mn, ans);
	}
	ans = max(abs(a[n - 1] - a[0]), ans);
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

