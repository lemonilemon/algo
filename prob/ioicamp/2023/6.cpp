#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN = 5e5 + 5;
struct Node {	
	ll mx, sum, _modtag, _addtag; 
	Node(): mx(0), sum(0), _modtag(0), _addtag(0) {}
	Node(ll val): mx(val), sum(val), _modtag(0), _addtag(0) {}
	Node(const Node& that): mx(that.mx), sum(that.sum), _modtag(that._modtag), _addtag(that._addtag) {}
	void modtag(ll x, int l, int r) {
		mx = x;
		sum = (r - l + 1) * x;
		_modtag = x;
		_addtag = 0;
	}
	void addtag(ll x, int l, int r) {
		mx += x;
		sum += (r - l + 1) * x;
		_addtag += x;
	}
	Node& operator = (const Node& that) {
		mx = that.mx;
		sum = that.sum;
		return *this;
	}
	Node operator + (const Node& that) const {
		Node ret;	
		ret.mx = max(mx, that.mx);
		ret.sum = sum + that.sum;
		return ret;
	}
} node[MAXN << 2];
int N, Q;
int a[MAXN];
void pull(int v) {
	node[v] = node[v << 1] + node[v << 1 | 1];
}
void push(int v, int l, int r) {
	int mid = (l + r) >> 1;
	ll modtag = node[v]._modtag;
	node[v]._modtag = 0;
	if(modtag) {
		node[v << 1].modtag(modtag, l, mid);	
		node[v << 1 | 1].modtag(modtag, mid + 1, r);
	}
	ll addtag = node[v]._addtag;
	node[v]._addtag = 0;
	if(addtag) {
		node[v << 1].addtag(addtag, l, mid);	
		node[v << 1 | 1].addtag(addtag, mid + 1, r);
	}
}
void build(int l = 1, int r = N, int v = 1) {
	if(l == r) {
		node[v] = Node(a[l]);	
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
	return;
}
void mod_modify(int ql, int qr, ll val, int l = 1, int r = N, int v = 1) {
	if(ql == l && qr == r) {
		node[v].modtag(val, l, r);
		return;
	}
	push(v, l, r);
	int mid = (l + r) >> 1;
	if(qr <= mid) mod_modify(ql, qr, val, l, mid, v << 1);
	else if(ql > mid) mod_modify(ql, qr, val, mid + 1, r, v << 1 | 1);
	else {
		mod_modify(ql, mid, val, l, mid, v << 1);	
		mod_modify(mid + 1, qr, val, mid + 1, r, v << 1 | 1);
	}
	pull(v);
}
void add_modify(int ql, int qr, ll val, int l = 1, int r = N, int v = 1) {
	if(ql == l && qr == r) {
		node[v].addtag(val, l, r);
		return;
	}
	push(v, l, r);
	int mid = (l + r) >> 1;
	if(qr <= mid) add_modify(ql, qr, val, l, mid, v << 1);
	else if(ql > mid) add_modify(ql, qr, val, mid + 1, r, v << 1 | 1);
	else {
		add_modify(ql, mid, val, l, mid, v << 1);	
		add_modify(mid + 1, qr, val, mid + 1, r, v << 1 | 1);
	}
	pull(v);
}
Node query(int ql, int qr, int l = 1, int r = N, int v = 1) {
	if(ql == l && qr == r) return node[v];
	push(v, l, r);
	int mid = (l + r) >> 1;	
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;		
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
	}
	build();
	for(int i = 0; i < Q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			mod_modify(l, r, x);
		} else if(op == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			add_modify(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			Node ans = query(l, r);
			if(op == 3) cout << ans.sum << '\n';
			else cout << ans.mx << '\n';
		}
	}
}
