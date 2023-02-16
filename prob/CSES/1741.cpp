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
const int MAXX = 1e6 + 5, MAXY = 1e6 + 5;
vector<pair<pair<int, int>, int> > event[MAXY << 1];
struct Node {
	int mn, mncnt, addtag;
	Node(): mn(0), mncnt(1), addtag(0) {}
	Node(const Node& that): mn(that.mn), mncnt(that.mncnt), addtag(that.addtag) {}
	Node& operator = (const Node& that) {
		mn = that.mn;
		mncnt = that.mncnt;
		return *this;
	}
	Node operator + (const Node& that) const {
		if(mn < that.mn) return *this;
		if(that.mn < mn) return that;	
		Node ret = Node(*this);
		ret.mncnt += that.mncnt;
		return ret;
	}
	void tag(int val) {
		mn += val;
		addtag += val;
	}
} seg[MAXX << 2];
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void push(int v) {
	if(seg[v].addtag) {
		int& addtag = seg[v].addtag;
		seg[v << 1].tag(addtag);
		seg[v << 1 | 1].tag(addtag);
		addtag = 0;	
	}
}
void build(int l = 1, int r = (MAXX << 1) - 1, int v = 1) {
	if(l == r) {
		seg[v] = Node();
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int val, int ql, int qr, int l = 1, int r = (MAXX << 1) - 1, int v = 1) {
	if(ql == l && qr == r) {
		seg[v].tag(val);
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if(qr <= mid) modify(val, ql, qr, l, mid, v << 1);
	else if(ql > mid) modify(val, ql, qr, mid + 1, r, v << 1 | 1);
	else {
		modify(val, ql, mid, l, mid, v << 1);
		modify(val, mid + 1, qr, mid + 1, r, v << 1 | 1);
	}
	pull(v);
}
Node query(int ql = 1, int qr = (MAXX << 1) - 1, int l = 1, int r = (MAXX << 1) - 1, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	push(v);
	int mid = (l + r) >> 1;	
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1); 
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);	
}
void solve() {
	int N;
	cin >> N;
	build();
	for(int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += MAXX;
		y1 += MAXY;
		x2 += MAXX;
		y2 += MAXY;
		debug(x1), debug(x2), debug(y1), debug(y2);
		event[y1].push_back(make_pair(make_pair(x1, x2), 1));
		event[y2 + 1].push_back(make_pair(make_pair(x1, x2), -1));
	}
	ll ans = 0;
	/*for(int i = 1; i < (MAXY << 1); ++i) {
		for(auto [range, val] : event[i]) {
			auto [l, r] = range;
			debug(val), debug(l), debug(r);
			modify(val, l, r);
		}
		debug(ans);
		ans += (MAXX << 1) - 1 - seg[1].mncnt;
	}*/
	cout << ans << '\n';
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

