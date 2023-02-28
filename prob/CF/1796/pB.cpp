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
	string a, b;
	cin >> a >> b;
	if(a[0] == b[0]) {
		cout << "YES\n";
		cout << a[0] << "*\n";
		return;
	}
	if(a.back() == b.back()) {
		cout << "YES\n";
		cout << '*' << a.back() << '\n';
		return;
	}
	for(int i = 0; i < (int)a.size() - 1; ++i) {
		for(int j = 0; j < (int)b.size() - 1; ++j) {
			if(a[i] == b[j] && a[i + 1] == b[j + 1]) {
				cout << "YES\n";
				cout << '*' << a[i] << a[i + 1] << "*\n";
				return;
			}
		}
	}
	cout << "NO\n";
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

