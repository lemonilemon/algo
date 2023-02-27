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
const int MAXN = 40;
ll val[1 << (MAXN >> 1)];
void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> l, r;
	for(int i = 0; i < (n >> 1); ++i){
		int t;
		cin >> t;
		l.emplace_back(t);
	}
	for(int i = n >> 1; i < n; ++i) {
		int t;
		cin >> t;
		r.emplace_back(t);
	}
	unordered_map<ll, int> mp;
	val[0] = 0;
	++mp[0];
	for(int i = 1; i < (1 << (n >> 1)); ++i) {
		val[i] = val[i ^ (1 << __lg(i))] + l[__lg(i)];
		++mp[val[i]];
	}
	val[0] = 0;
	ll ans = mp[x];
	for(int i = 1; i < (1 << (int)r.size()); ++i) {
		val[i] = val[i ^ (1 << __lg(i))] + r[__lg(i)];
		ans += mp[x - val[i]];
	}
	cout << ans << '\n';
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

