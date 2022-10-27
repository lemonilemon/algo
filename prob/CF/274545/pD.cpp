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
const int MAXN = 1e5 + 5;
int seg[MAXN << 3];
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l = 1, int r = MAXN << 1, int v = 1) {
	if(l == r) {
		seg[v] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int q, int val, int l = 1, int r = MAXN << 1, int v = 1) {
	if(l == r) {
		seg[v] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int query(int ql, int qr, int l = 1, int r = MAXN << 1, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
int color[MAXN];
struct Range {
	int num, l, r;
	bool operator < (const Range& that) const {
		return l == that.l? r < that.r : l > that.l;
	}
} p[MAXN];
int ans[MAXN];
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		p[i].num = i;
	}
	for(int i = 1; i <= (n << 1); ++i) {
		int x;
		cin >> x;
		if(color[x]) {
			color[x] = 2;
			p[x].r = i;
		} else {
			color[x] = 1;
			p[x].l = i;
		}
	}
	sort(p + 1, p + n + 1);
	safe();
	build();
	for(int i = 1; i <= n; ++i) {
		auto [num, l, r] = p[i];
		debug(l), debug(r);
		ans[num] = r - l - 1 - 2 * query(l, r);
		modify(r, 1);
	}
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
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

