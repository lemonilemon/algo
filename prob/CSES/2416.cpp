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
const int MAXN = 2e5 + 5, MAXQ = 2e5 + 5;
const ll INF = 1e18 + 7;
struct Node {
	int sz;
	ll sum, add;
	Node(): sz(1), sum(0), add(0) {}
	Node(ll x): sz(1), sum(x), add(0) {}
	Node(const Node& that): sum(that.sum), add(that.add) {}
	Node& operator = (const Node& that) {
		sum = that.sum;
		sz = that.sz;
		return *this;
	}
	Node operator + (const Node& that) {
		Node ret;
		ret.sum = sum + that.sum;
		ret.sz = sz + that.sz;
		return ret;
	}
	void tag(ll val) {
		add += val;
		sum += val * sz;
	}
} seg[MAXN << 2];
ll x[MAXN];
ll ans[MAXQ];
void push(int v) {
	seg[v << 1].tag(seg[v].add);
	seg[v << 1 | 1].tag(seg[v].add);
	seg[v].add = 0;
}
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = Node();
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int ql, int qr, ll val, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) {
		seg[v].tag(val);
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if(qr <= mid) modify(ql, qr, val, l, mid, v << 1);
	else if(ql > mid) modify(ql, qr, val, mid + 1, r, v << 1 | 1);
	else {
		modify(ql, mid, val, l, mid, v << 1);
		modify(mid + 1, qr, val, mid + 1, r, v << 1 | 1);
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
vector<pair<int, int> > quest[MAXN]; // l -> (r, ord)
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for(int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		quest[l].push_back(make_pair(r, i));
	}
	vector<pair<ll, int> > mx; // (val, pos)
	mx.push_back(make_pair(INF, n + 1));
	build();
	for(int l = n; l > 0; --l) {
		debug(l), debug(x[l]);
		while(x[l] >= mx.back().first) {
			auto [orimx, orimxl] = mx.back();
			mx.pop_back();	
			int orimxr = mx.back().second - 1; // [orimxl, orimxr]
			modify(orimxl, orimxr, x[l] - orimx);
		}
		mx.push_back(make_pair(x[l], l));
		for(auto [r, ord] : quest[l]) {
			ans[ord] = query(l, r).sum;
		}
	}
	for(int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
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

