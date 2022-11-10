#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int MAXK = 1e5 + 5;
bool avail[MAXK];
int a[MAXK];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	ll space = 1ll * n * m - 4;
	for(int i = 0; i <= k; ++i) {
		avail[i] = 0;
	}
	int cur = k;
	for(int i = 1; i <= k; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= k; ++i) {
		avail[a[i]] = 1; 
		--space;
		while(avail[cur]) {
			--cur;
			++space;
		}
		if(space < 0) {
			cout << "TIDAK\n";
			safe();
			return;
		}
	}
	cout << "YA\n";
	safe();
	return;
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

