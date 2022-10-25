#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
void safe() {
	std::cerr<<"\033[1;32m"<<__PRETTY_FUNCTION__<<" is safe\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
const int MAXN = 1e5 + 5, C = 1e6 + 5;
vector<int> add[C << 1], del[C << 1];
vector<pair<int, int> > q[C << 1]; 
int BIT[C << 1];
void modify(int k, int val) {
	for(; k < (C << 1); k += k & -k) BIT[k] += val;
}
int query(int k) {
	int ret = 0;
	for(; k > 0; k -= k & -k) ret += BIT[k];
	return ret;
}
void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += C, x2 += C, y1 += C, y2 += C;
		if(x1 == x2) q[x1].push_back(make_pair(y1, y2));	
		else {
			add[x1].push_back(y1);
			del[x2 + 1].push_back(y1);
		}
	}
	ll ans = 0;
	for(int x = 0; x < (C << 1); ++x) {
		for(auto y : add[x]) {
			modify(y, 1);
		}
		for(auto y : del[x]) {
			modify(y, -1);
		}
		for(auto [y1, y2] : q[x]) {
			ans += query(y2) - query(y1 - 1);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

