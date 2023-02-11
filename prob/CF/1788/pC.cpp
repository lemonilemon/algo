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

void solve() {
	ll n;
	cin >> n;
	if(!(n & 1)) {
		cout << "No\n";
		return;
	}
	ll s1 = (3 * n + 3) >> 1;
	cout << "Yes\n";
	for(int i = 1, j = s1 - 1; i <= (n >> 1) + 1 && j <= 2 * n; ++i, ++j) {
		cout << i << ' ' << j << '\n';	
	}
	for(int i = (n >> 1) + 2, j = s1 + 1 - i; i < s1 - (n >> 1) - 1 && j < s1 - 1; ++i, ++j) {
		cout << i << ' ' << j << '\n';
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

