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

using pii = pair<ll, ll>;
#define X first
#define Y second
pii operator + (pii a, pii b) {
	return make_pair(a.X + b.X, a.Y + b.Y);
}
pii operator - (pii a, pii b) {
	return make_pair(a.X - b.X, a.Y - b.Y);
}
ll operator * (pii a, pii b) {
	return a.X * b.X + a.Y + b.Y;
}
ll operator ^ (pii a, pii b) {
	return a.X * b.Y - a.Y * b.X;
}
void solve() {
	int n;
	cin >> n;
	vector<pii> points(n);
	for(auto& [x, y] : points) {
		cin >> x >> y;
	}
	points.emplace_back(points.front());
	ll area = 0;
	for(int i = 0; i < n; ++i) {
		area += points[i] ^ points[i + 1];
	}
	area = abs(area) >> 1;
	ll b = n;
	for(int i = 0; i < n; ++i) {
		auto p = points[i + 1] - points[i];
		b += gcd(p.X, p.Y) - 1;
	}
	// pick's theorem S = I + B/2 - 1	
	cout << area + 1 - b / 2 << ' ' << b;
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

