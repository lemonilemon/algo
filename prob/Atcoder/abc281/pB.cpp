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
	string s;
	cin >> s;
	if(s.size() != 8) {
		cout << "No\n";
		return;
	}
	if(s[0] > 'Z' || s[0] < 'A') {
		cout << "No\n";
		return;
	}
	if(s[1] < '1' || s[1] > '9') {
		cout << "No\n";
		return;
	}
	for(int i = 2; i <= 6; ++i) {
		if(s[i] < '0' || s[i] > '9') {
			cout << "No\n";
			return;
		}
	}
	if(s[7] > 'Z' || s[7] < 'A') {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";

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

