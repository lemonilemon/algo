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
struct Rec {
	int x1, y1, x2, y2;
};
const int MAXX = 1e6 + 5, MAXY = 1e6 + 5, MAXN = 1e5 + 5, MAXSZ = MAXX << 1;
struct ST {
	int sz;
	struct Node {
		int mn, mncnt, addtag, sz;
		Node *lc, *rc;
		Node(): mn(0), mncnt(1), addtag(0), sz(1), lc(nullptr), rc(nullptr) {}
		Node(int _sz): mn(0), mncnt(_sz), addtag(0), sz(_sz), lc(nullptr), rc(nullptr) {}
		Node(const Node& that): mn(that.mn), mncnt(that.mncnt), addtag(0), sz(that.sz), lc(that.lc), rc(that.rc) {}
		Node& operator = (const Node& that) {
			mn = that.mn;
			mncnt = that.mncnt;
			sz = that.sz;
			return *this;
		}
		Node operator + (const Node& that) const {
			Node ret;
			if(mn < that.mn) ret = *this;
			else if(that.mn < mn) ret = that;
			else {
				ret = *this;
				ret.mncnt += that.mncnt;
			}
			ret.sz = sz + that.sz;
			return ret;
		}
		Node* lchild() {
			return lc? lc : lc = new Node((sz >> 1) + (sz & 1));
		}
		Node* rchild() {
			return rc? rc : rc = new Node(sz >> 1);
		}	
		void tag(int val) {
			mn += val;
			addtag += val;
		}
		void pull() {
			*this = *lchild() + *rchild();
		}
		void push() {
			if(addtag) {
				lchild() -> tag(addtag);
				rchild() -> tag(addtag);
				addtag = 0;
			}
		}
	} *root;
	ST(int _sz): sz(_sz), root(new Node(sz)) {}
	void modify(int val, int ql, int qr) {
		_modify(val, ql, qr, 1, sz, root);
	}
	void _modify(int val, int ql, int qr, int l, int r, Node* node) {
		if(ql == l && qr == r) {
			node -> tag(val);
			return;
		}
		node -> push();
		int mid = (l + r) >> 1;
		if(qr <= mid) _modify(val, ql, qr, l, mid, node -> lchild());
		else if(ql > mid) _modify(val, ql, qr, mid + 1, r, node -> rchild());
		else {
			_modify(val, ql, mid, l, mid, node -> lchild());
			_modify(val, mid + 1, qr, mid + 1, r, node -> rchild());
		}
		node -> pull();
	}
	int query() {
		return root -> mncnt;
	}
};
map<int, vector<pair<pair<int, int>, int> > > event;
void solve() {
	int N;
	cin >> N;
	ST st(MAXSZ);
	vector<Rec> rec(N);
	for(auto& [x1, y1, x2, y2] : rec) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += MAXX;
		x2 += MAXX;
		y1 += MAXY;
		y2 += MAXY;
		event[y1].push_back(make_pair(make_pair(x1, x2 - 1), 1));
		event[y2].push_back(make_pair(make_pair(x1, x2 - 1), -1));
	}
	ll ans = 0;
	ll lastval = 0, lastt = 0;
	for(auto [t, e] : event) {
		for(auto [range, val] : e) {
			auto [l, r] = range;
			st.modify(val, l, r);
		}
		ans += (t - lastt) * lastval;
		lastval = MAXSZ - st.query();
		lastt = t;
	}
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

