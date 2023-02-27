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
const ll INF = 1e18 + 9, MAXN = 2e5 + 5, MAXS = 1e6 + 5;
struct Line {
	ll m, k;
	Line(): m(0), k(INF) {}
	Line(ll _m, ll _k): m(_m), k(_k) {}
	ll operator () (const ll& x) const {
		return m * x + k;
	}
};
Line lichou[MAXS << 2];
void insert(Line line, int l = 1, int r = MAXS, int v = 1) {
	if(l == r) {
		if(line(l) < lichou[v](l)) lichou[v] = line;
		return;
	}
	if(line.m > lichou[v].m) swap(lichou[v], line);
	int mid = (l + r) >> 1;
	if(line(mid) < lichou[v](mid)) {
		swap(line, lichou[v]);	
		insert(line, l, mid, v << 1);
	} else insert(line, mid + 1, r, v << 1 | 1);
}
ll query(ll x, int l = 1, int r = MAXS, int v = 1) {
	//debug(x);
	//debug(lichou[v](x));
	if(l == r) return lichou[v](x);
	int mid = (l + r) >> 1;
	if(x <= mid) return min(lichou[v](x), query(x, l, mid, v << 1));
	return min(lichou[v](x), query(x, mid + 1, r, v << 1 | 1));
}
ll dp[MAXN], s[MAXN], f[MAXN];
void solve() {
	int n;
	cin >> n >> f[0];
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];	
	}
	for(int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	safe();
	dp[0] = 0;
	insert(Line(f[0], dp[0]));
	for(int i = 1; i <= n; ++i) {
		dp[i] = query(s[i]);
		insert(Line(f[i], dp[i]));
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

