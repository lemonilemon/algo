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
const int MAXN = 1e5 + 5, INF = 1e9 + 7;
int a[MAXN];
int seg[MAXN << 2];
void pull(int v) {
	seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
void build(int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int q, int val, int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int lb(int x, int l = 1, int r = MAXN, int v = 1) {
	if(seg[v] < x) return INF;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(seg[v << 1] >= x) return lb(x, l, mid, v << 1);	
	return lb(x, mid + 1, r, v << 1 | 1);
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build();
	for(int i = 0; i < m; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int x, val;
			cin >> x >> val;
			++x;
			modify(x, val);
		} else {
			int x;
			cin >> x;
			int ans = lb(x);
			if(ans == INF) cout << "-1\n";
			else cout << ans - 1 << '\n';
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

