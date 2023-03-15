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
const int MAXN = 2e5 + 5, MAXQ = 2e5 + 5;
struct Node {
	ll sum;
	Node *lc, *rc;	
	Node() {}
	Node(ll x): sum(x), lc(NULL), rc(NULL) {}
	Node(const Node& that): sum(that.sum), lc(that.lc), rc(that.rc) {}
	Node* lchild() {
		return lc? lc : lc = new Node();
	}
	Node* rchild() {
		return rc? rc : rc = new Node();
	}
	void pull() {
		sum = lc -> sum + rc -> sum;
	}
} *root[MAXQ];
ll t[MAXN];
Node* build(int l, int r) {
	if(l == r) return new Node(t[l]);
	int mid = (l + r) >> 1;
	Node *ret = new Node;
	ret->lc = build(l, mid);
	ret->rc = build(mid + 1, r);
	ret -> pull();
	return ret;
}
Node* modify(int q, ll val, int l, int r, Node* cur) {
	if(l == r) return new Node(val);	
	Node* ret = new Node(*cur);
	int mid = (l + r) >> 1;
	if(q <= mid) ret -> lc = modify(q, val, l, mid, cur -> lc);
	else ret -> rc = modify(q, val, mid + 1, r, cur -> rc);
	ret -> pull();
	return ret;
}
ll query(int ql, int qr, int l, int r, Node* cur) {
	if(ql == l && qr == r) return cur -> sum;
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, cur -> lc);
	if(ql > mid) return query(ql, qr, mid + 1, r, cur -> rc);
	return query(ql, mid, l, mid, cur -> lc) + query(mid + 1, qr, mid + 1, r, cur -> rc);
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	root[0] = build(1, n);
	int cnt = 1;
	vector<int> pos;
	pos.emplace_back(0);
	for(int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int k, a, x;
			cin >> k >> a >> x;
			--k;
			root[cnt] = modify(a, x, 1, n, root[pos[k]]);
			pos[k] = cnt++;
		} else if(op == 2) {
			int k, a, b;
			cin >> k >> a >> b;
			--k;
			cout << query(a, b, 1, n, root[pos[k]]) << '\n';
		} else {
			int k;
			cin >> k;
			--k;
			pos.emplace_back(cnt);
			root[cnt++] = new Node(*root[pos[k]]);
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

