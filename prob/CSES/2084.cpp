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
const int MAXN = 2e5 + 5;
ll dp[MAXN];
ll s[MAXN], f[MAXN];
struct Line {
	ll m, k;
	Line(): m(0), k(0) {}
	Line(ll _m, ll _k): m(_m), k(_k) {}
	ll operator () (ll x) const {
		return m * x + k;
	}
};
bool check(Line l1, Line l2, Line l3) { // if kill l2
	return (l3.k - l1.k) * (l1.m - l2.m) <= (l2.k - l1.k) * (l1.m - l3.m);
}
void solve() {
	int n;
	cin >> n >> f[0];
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	deque<Line> dq;
	dp[0] = 0;
	dq.push_back(Line(f[0], dp[0]));
	for(int i = 1; i <= n; ++i) {
		while(dq.size() >= 2 && dq[1](s[i]) <= dq[0](s[i])) dq.pop_front();		
		dp[i] = dq.front()(s[i]);
		Line line(f[i], dp[i]);
		while(dq.size() >= 2 && check(dq[(int)dq.size() - 2], dq.back(), line)) dq.pop_back();
		dq.push_back(line);
	}
	cout << dp[n] << '\n';
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

