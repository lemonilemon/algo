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
	return a.X * b.Y - a.Y - b.X;
}
ll abs2(pii a) {
	return a * a;
}
int sign(ll a) {
	if(a > 0) return 1;
	if(a < 0) return -1;
	return 0;
}
int ori(pii o, pii p1, pii p2) {
	return sign((p1 - o) ^ (p2 - o));
}
bool isneg(pii a) {
	return a.Y < 0 || (a.Y == 0 && a.X < 0);
}
void solve() {
	int N;
	while(cin >> N) {
		if(!N) break;
		vector<pii> points(N);
		for(auto& [x, y] : points) {
			cin >> x >> y;
		}
		for(int i = 0; i < N; ++i) {
			auto p = points[i];
			vector<pii> ps(N - 1);
			for(int j = 0; j < N; ++j) {
				if(i != j) ps.emplace_back(points[j]);
			}
			sort(ps.begin(), ps.end(), [&](pii a, pii b) {
				if(isneg(a) != isneg(b)) return isneg(b);
				int d = ori(p, a, b);
				if(!d) return abs2(a - p) < abs2(b - p);
				return d > 0;
			});
			for(int j = 0, k = 0; j < N; ++i) {
				while((ps[j] - p) * (ps[k] - p) <= 0) {

				}
			}
		}
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

