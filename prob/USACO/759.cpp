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
FILE* setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
struct Rec {
	int x1, y1, x2, y2;
	Rec(){}
	Rec(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
	bool contain(const Rec& that) const {
		return x1 <= that.x1 && y1 <= that.y1 && x2 >= that.x2 && y2 >= that.y2;
	}
} rec[3];
void solve() {
	for(int i = 0; i < 3; ++i) {
		auto& [x1, y1, x2, y2] = rec[i];
		cin >> x1 >> y1 >> x2 >> y2;
	}
	int cnt = 0;
	for(int x = -1000; x <= 1000; ++x) {
		for(int y = -1000; y <= 1000; ++y) {
			Rec block(x, y, x + 1, y + 1);
			if(rec[2].contain(block)) continue;
			cnt += rec[1].contain(block) || rec[0].contain(block);
		}
	}
	cout << cnt << '\n';
}

int main() {
	setIO("billboard");
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

