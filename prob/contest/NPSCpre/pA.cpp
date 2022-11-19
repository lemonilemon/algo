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
const int MAXN = 4e3 + 5, D = 11;
char ch[MAXN][MAXN], ans[MAXN][MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin >> ch[i][j];
		}
	}
	for(int i = 0; i < N; i += D) {
		for(int j = 0; j < N; ++j) {
			if(ch[i][j] == '.') ch[i][j] = 'O';
		}
	}
	for(int i = 0; i < N; ++i) {
		if(ch[N - 1][i] == '.') ch[N - 1][i] = 'O';
	}
	for(int i = 0; i < N; ++i) {
		if(ch[i][0] == '.') ch[i][0] = 'O';
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(ch[i][j] == 'P') {
				int l = (i / D) * D, r = min(N - 1, (i / D + 1) * D);
				if(i - l < r - i) {
					for(int k = l + 1; k < i; ++k) {
						if(ch[k][j] == '.') ch[k][j] = 'O';
					}
				} else {
					for(int k = i + 1; k < r; ++k) {
						if(ch[k][j] == '.') ch[k][j] = 'O';
					}
				}
			}
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << ch[i][j];
		}
		cout << '\n';
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

