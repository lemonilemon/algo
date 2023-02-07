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
const int MAXN = 2005;
ll a[MAXN];
void solve() {
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	unordered_map<ll, int> mp;
	for(int k = 0; k < n; ++k) {
		for(int l = k + 1; l < n; ++l) {
			ll val = a[k] + a[l];
			if(mp.count(val)) ++mp[val];
			else mp[val] = 1;
		}
	}
	ll cnt = 0;
	
	for(int j = 0; j < n; ++j) {
		for(int l = j + 1; l < n; ++l) {
			int k = j;
			ll val = a[k] + a[l];
			--mp[val];
			if(!mp[val]) mp.erase(val);
		}
		for(int i = 0; i < j; ++i) {
			ll val = a[i] + a[j];	
			if(mp.count(x - val)) cnt += mp[x - val];
		}
	}	
	cout << cnt << '\n';
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

