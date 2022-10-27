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
const int MAXN = 1e5 + 5, MAXY = 41;
int p[MAXN + 5];
struct Node {
	int cnt;
	map<int, int> freq;
	Node(): cnt(0) {}
	Node(int x): Node() {
		freq[x] = 1;
	}
	Node(const Node& that) {
		cnt = that.cnt;
		freq = that.freq;
	}
	Node operator + (const Node& that) const {
		Node ret;
		ret.cnt = cnt + that.cnt;
		for(auto [kl, vl] : freq) { // in this
			for(auto [kr, vr] : that.freq) { // in that
				if(kr >= kl) break;
				ret.cnt += vl * vr;
			}
		}
		if(freq.size() > that.freq.size()) {
			ret.freq = freq;
			for(auto [k, v] : that.freq) {
				if(ret.freq.count(k)) ret.freq[k] += v;
				else ret.freq[k] = v;
			}
		} else {
			ret.freq = that.freq;
			for(auto [k, v] : freq) {
				if(ret.freq.count(k)) ret.freq[k] += v;
				else ret.freq[k] = v;
			}
		}
		return ret;
	}
	Node& operator = (const Node& that) {
		cnt = that.cnt;
		freq = that.freq;
		return *this;
	}
} seg[MAXN << 1];
int n, q;
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l = 1, int r = n, int v = 1) {
	if(l == r) {
		seg[v] = Node(p[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int q, int val, int l = 1, int r = n, int v = 1) {
	if(l == r) {
		seg[v] = Node(val);
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
Node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	build();
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r;
			cin >> l >> r;
			cout << query(l, r).cnt << '\n';
		} else {
			int x, val;
			cin >> x >> val;
			modify(x, val);
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

