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
struct Node {
	int sz;
	ll sum;
	ll m, k;
	Node(): sz(1), sum(0), m(0), k(0) {}
	Node(ll x): sz(1), sum(x), m(0), k(0) {}
	Node(const Node& that) {
		sz = that.sz;
		sum = that.sum;
		m = that.m;
		k = that.k;
	}
	Node operator + (const Node& that) const {
		Node ret;
		ret.sz = sz + that.sz;
		ret.sum = sum + that.sum;
		return ret;
	}
	Node& operator = (const Node& that) {
		sz = that.sz;
		sum = that.sum;
		return *this;
	}
	void tag(ll a, ll b) { // ax + b
		sum += (((a + b) + (a * sz + b)) * sz) >> 1;
		m += a;
		k += b;
	}
} seg[MAXN << 2];
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void push(int v) {
	seg[v << 1].tag(seg[v].m, seg[v].k);
	seg[v << 1 | 1].tag(seg[v].m, seg[v << 1].sz * seg[v].m + seg[v].k);
	seg[v].m = 0;
	seg[v].k = 0;
}
int a[MAXN + 5];
void build(int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = Node(a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int ql, int qr, ll m, ll k, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) {
		seg[v].tag(m, k);
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if(qr <= mid) modify(ql, qr, m, k, l, mid, v << 1);
	else if(ql > mid) modify(ql, qr, m, k, mid + 1, r, v << 1 | 1);
	else {
		modify(ql, mid, m, k, l, mid, v << 1);
		modify(mid + 1, qr, m, (mid - ql + 1) * m + k, mid + 1, r, v << 1 | 1);
	}
	pull(v);
}
Node query(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	push(v);
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build();
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r;
			cin >> l >> r;
			modify(l, r, 1, 0);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r).sum << '\n';
		}
	}
	return;
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

