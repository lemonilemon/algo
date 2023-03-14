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
const int MAXN = 1e6 + 5;
int fail[MAXN];
void getfail(string s) {
	fail[0] = -1;	
	int pos = -1;
	for(int i = 1; i < (int)s.size(); ++i) {
		while(~pos && s[i] != s[pos + 1]) pos = fail[pos];
		if(s[pos + 1] == s[i]) ++pos;
		fail[i] = pos;
	}
}
void solve() {
	string s, t;
	cin >> s >> t;
	getfail(t);
	int pos = -1;
	int cnt = 0;
	for(int i = 0; i < (int)s.size(); ++i) {
		if(~pos && s[i] != t[pos + 1]) pos = fail[pos];
		if(s[i] == t[pos + 1]) ++pos;
		if(pos + 1 == (int)t.size()) {
			++cnt;
			pos = fail[pos];
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

