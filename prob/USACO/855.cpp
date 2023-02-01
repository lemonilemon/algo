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
FILE* setIO(string file = "mixmilk") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
int m[3], c[3];
void pour(int from, int to) {
	int total = m[from] + m[to];
	if(total > c[to]) {
		m[to] = c[to];
		m[from] = total - c[to];
	} else {
		m[from] = 0;
		m[to] = total;
	}
}
void solve() {
	for(int i = 0; i < 3; ++i) {
		cin >> c[i] >> m[i];
	}
	for(int i = 0; i < 100; ++i) {
		switch(i % 3) {
			case 0:
				pour(0, 1);		
				break;
			case 1:
				pour(1, 2);
				break;
			case 2:
				pour(2, 0);	
				break;
		}
	}
	for(int i = 0; i < 3; ++i) {
		cout << m[i] << '\n';
	}
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

