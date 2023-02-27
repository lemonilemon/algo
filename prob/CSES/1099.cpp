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
const int MAXX = 7;
int sg[MAXX + 1][(MAXX << 1) + 1]; // i -> j
void test() {
	for(int i = 0; i <= (MAXX << 1); ++i) {
		sg[0][i] = i;
	}
	for(int i = 1; i <= MAXX; ++i) {
		for(int j = 0; i + j <= (MAXX << 1); ++j) {
			set<int> s;
			for(int k = 1; k <= i; ++k) {
				s.insert(sg[i - k][j + k]);	
			}
			for(int k = 1; k <= j; ++k) {
				s.insert(sg[i][j - k]);
			}
			for(int k = 0; k <= MAXX << 1; ++k) {
				if(!s.count(k)) {
					sg[i][j] = k;
					break;
				}
			}
			debug(i), debug(j), debug(sg[i][j]);
		}
	}
}
void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << "second\n";
		return;
	}
	int sg = 0;
	int p;
	cin >> p;
	cin >> sg;
	for(int i = 3; i <= n; ++i) {
		cin >> p;
		if(sg) sg = p - 1;
		else sg = p - 2;
		sg = max(sg, 0);
	}
	if(sg) cout << "first\n";
	else cout << "second\n";
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	test();
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		//solve();
	}
}

