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
const int MAXC = 1e9 + 7, MAXQ = 2e5 + 5;
vector<int> vals;
int discrete(int x, bool reverse) {
	if(reverse) return vals[x - 1];
	return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}
struct Line {
	int m, k;
	Line(): m(0), k(0) {}
	Line(int m, int k): m(m), k(k) {}
	Line(const Line& that): m(that.m), k(that.k) {}
	ll operator () (const ll& x) const {
		return m * x + k;
	}
	Line& operator = (const Line& that) {
		m = that.m;
		k = that.k;
		return *this;
	}
	bool operator == (const Line& that) const {
		return m == that.m && k == that.k;
	}
	bool operator != (const Line& that) const {
		return m != that.m || k != that.k;
	}
};

struct ST {
	struct Node {
		Line line;
		Node *lc, *rc;
		Node() {}
		Node(const Line& line): line(line) {}
		Node(const Node& that): line(that.line), lc(that.lc), rc(that.rc) {}
		Node& operator = (const Node& that) {
			line = that.line;
			return *this;
		}
		Node* lchild() {
			return lc? lc : lc = new Node;
		}
		Node* rchild() {
			return rc? rc : rc = new Node;
		}
	} *root;
	int sz;
	vector<pair<Node*, Line> > mod;
	vector<vector<pair<Node*, Line> > > stk_mod;
	ST() {}
	ST(int sz): root(new Node), sz(sz) {}
	void init(int _sz) {
		sz = _sz;
	}
	void _insert(Line line, int l, int r, Node* cur) {
		Line temp(cur->line);
		if(l == r) {
			int val = discrete(l, 1);
			if(line(val) > cur->line(val)) cur->line = line;
			return;
		}
		int mid = (l + r) >> 1;
		if(line.m > cur->line.m) swap(line, cur->line);
		int val = discrete(mid, 1);
		if(line(val) > cur->line(val)) {
			swap(line, cur->line);
			_insert(line, mid + 1, r, cur->rchild());	
		} else _insert(line, l, mid, cur->lchild());
		if(cur->line != temp) mod.push_back(make_pair(cur, temp));
	}
	bool insert(Line line) {
		_insert(line, 1, sz, root);
		if(mod.empty()) return 0;
		stk_mod.push_back(mod);
		return 1;
	}
	ll _query(const ll& x, int l, int r, Node* cur) const {
		int val = discrete(x, 1);
		ll ans = cur->line(val);
		if(l == r) return ans;
		int mid = (l + r) >> 1;
		if(x <= mid) return max(ans, _query(x, l, mid, cur->lchild()));
		return max(ans, _query(x, mid + 1, r, cur->rchild()));
	}
	ll query(const ll& x) const {
		return _query(x, 1, sz, root);	
	}
	void undo() {
		for(auto& [ptr, line] : stk_mod.back()) {
			*ptr = line;
		}
		stk_mod.pop_back();
	}
} st(MAXQ);

vector<Line> tr[MAXQ << 2];
int quest[MAXQ];
ll ans[MAXQ];
int Q;
void insert_event(Line line, int ql, int qr, int l = 1, int r = Q, int v = 1) {
	debug(l), debug(r);
	if(ql == l && qr == r) {
		tr[v].push_back(line);
		return;
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) insert_event(line, ql, qr, l, mid, v << 1);
	else if(ql > mid) insert_event(line, ql, qr, mid + 1, r, v << 1 | 1);
	else {
		insert_event(line, ql, mid, l, mid, v << 1);
		insert_event(line, mid + 1, qr, mid + 1, r, v << 1 | 1);
	}
	return;
}
void traversal(int l = 1, int r = Q, int v = 1) {
	int cnt = 0;
	for(auto& line : tr[v]) {
		if(st.insert(line)) ++cnt;
	}
	if(l == r) {
		if(~quest[l]) ans[l] = st.query(quest[l]);
	} else {
		int mid = (l + r) >> 1;
		traversal(l, mid, v << 1);
		traversal(mid + 1, r, v << 1 | 1);
	}
	while(cnt--) st.undo();
}

Line seg[MAXQ];
int segst[MAXQ], seged[MAXQ];
int segcnt;
void solve() {
	cin >> Q;
	segcnt = 0;
	for(int i = 1; i <= Q; ++i) {
		quest[i] = -1;
		seged[i] = Q;
	}
	for(int i = 1; i <= Q; ++i) {
		int op;
		cin >> op;
		if(op == 0) {
			ll x;
			cin >> x;
			quest[i] = x;
			vals.push_back(x);
		} else if(op == 1) {
			ll m, k;
			cin >> m >> k;
			seg[segcnt] = Line(m, k);
			segst[segcnt] = i;
			++segcnt;
		} else {
			int k;
			cin >> k;
			seged[k] = i - 1;
		}
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	st.init(vals.size());
	for(int i = 1; i <= Q; ++i) {
		if(~quest[i]) quest[i] = discrete(quest[i], 0);
	}
	safe();
	for(int i = 0; i < segcnt; ++i) {
		debug(segst[i]);
		debug(seged[i]);
		insert_event(seg[i], segst[i], seged[i]);
	}
	safe();
	traversal();
	for(int i = 1; i <= Q; ++i) {
		if(~quest[i]) {
			if(ans[i]) cout << ans[i] << '\n';
			else cout << "double is good at problem setting\n";
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

