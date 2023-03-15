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
const int MAXN = 2000;
int sg[MAXN];
void init() {
	sg[1] = 0, sg[2] = 0;
	for(int i = 3; i < MAXN; ++i) {
		set<int> s;
		for(int j = 1; j < (i >> 1) + (i & 1); ++j) {
			s.insert(sg[j] ^ sg[i - j]);
		}
		sg[i] = 0;
		while(s.count(sg[i])) ++sg[i];
	}
	/*for(int i = 1; i < MAXN; ++i) {
		if(!sg[i]) debug(i);
	}*/
}
void solve() {
	int n;
	cin >> n;
	if(n < MAXN) {
		if(sg[n]) cout << "first\n";
		else cout << "second\n";
		return;
	}
	cout << "first\n";
}

int main() {
	setIO();
	init();
	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

