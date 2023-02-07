#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 1e6 + 5;
struct Event {
	int l, r;
	ll val;
	Event(int _l, int _r, int _val): l(_l), r(_r), val(_val) {}
};
vector<Event> event[MAXN];
struct Node {
	ll mn, mncnt, addtag; 
	Node(): mn(0), mncnt(1) {}
	void tag(int val) {
		mn += val;	
		addtag += val;
	}
	Node& operator = (const Node& that) {
		mn = that.mn;
		mncnt = that.mncnt;
		return *this;
	}
	Node operator + (const Node& that) const {
		Node ret;
		if(mn < that.mn) ret = *this;
		else if(that.mn < mn) ret = that;
		else {
			ret.mn = mn;
			ret.mncnt = mncnt + that.mncnt;
		}
		return ret;
	}
} st[MAXN << 2];
void pull(int v) {
	st[v] = st[v << 1] + st[v << 1 | 1];
}
void push(int v) {
	int addtag = st[v].addtag;
	st[v].addtag = 0;
	if(addtag) {
		st[v << 1].tag(addtag);
		st[v << 1 | 1].tag(addtag);
	}
}
void build(int l = 1, int r = MAXN - 1, int v = 1) {
	if(l == r) {
		st[v] = Node();
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int ql, int qr, ll val, int l = 1, int r = MAXN - 1, int v = 1) {
	if(ql == l && qr == r) {
		st[v].tag(val);
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
Node query(int ql, int qr, int l = 1, int r = MAXN - 1, int v = 1) {
	if(ql == l && qr == r) return st[v];	
	push(v);
	int mid = (l + r) >> 1;	
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1); 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int l, r, d, u;	
		cin >> l >> r >> d >> u;
		++l, ++r;
		event[d].emplace_back(Event(l, r - 1, 1));
		event[u].emplace_back(Event(l, r - 1, -1));
	}
	build();
	ll sum = 0;
	for(int t = 0; t < MAXN; ++t) {
		for(auto [l, r, val] : event[t]) {
			modify(l, r, val);
		}
		auto ans = query(1, MAXN - 1);
		if(ans.mn) sum += MAXN - 1;
		else sum += MAXN - 1 - ans.mncnt;
	}
	cout << sum << '\n';
}
