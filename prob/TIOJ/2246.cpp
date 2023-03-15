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
const int MAXC = 2e6 + 25, MAXN = 2505, MAXR = 10;
pair<ll, ll> points[MAXN];
void solve() {
	int n, r;
	cin >> n >> r;
	set<pair<int, int> > s;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		for(ll dx = -r; dx <= r; ++dx) {
			for(ll dy = -r; dy <= r; ++dy) {
				ll d2 = dx * dx + dy * dy;
				if(d2 <= r * r) {
					auto p = make_pair(x + dx, y + dy);
					if(s.count(p)) s.erase(p);
					else s.insert(p);	
				}
			}
		}
	}
	cout << s.size() << '\n';
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

