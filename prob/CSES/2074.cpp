#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
void safe() {
	std::cerr<<"\033[1;32m"<<__PRETTY_FUNCTION__<<" is safe\033[0m\n";
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
struct Treap {
	int sz, pri;
	ll val, sum;
	bool reverse;
	Treap *l, *r;
	Treap(int _val): sz(1), pri(rand()), val(_val), sum(_val), reverse(0), l(NULL), r(NULL) {}
};
int sz(Treap* t) {
	return t? t -> sz : 0;
}
ll sum(Treap* t) {
	return t? t -> sum : 0;
}
void reverse(Treap* t) {
	swap(t -> l, t -> r);
	t -> reverse = !t -> reverse;
}
void push(Treap* t) {
	if(t -> reverse) {
		if(t -> l) reverse(t -> l);
		if(t -> r) reverse(t -> r);
		t -> reverse = 0;
	}
}
void pull(Treap* t) {
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
	t -> sum = t -> val + sum(t -> l) + sum(t -> r);
}
Treap* merge(Treap* tl, Treap* tr) {
	if(!tl || !tr) return tl? tl : tr;
	if(tl -> pri > tr -> pri) {
		push(tl);
		tl -> r = merge(tl -> r, tr);
		pull(tl);
		return tl;
	} else {
		push(tr);
		tr -> l = merge(tl, tr -> l);
		pull(tr);
		return tr;
	}
}
void split(Treap *t, int k, Treap* &tl, Treap* &tr) {
	if(!t) {
		tl = tr = NULL;
		return;
	}
	if(sz(t -> l) + 1 <= k) {
		tl = t;
		push(tl);
		split(t -> r, k - sz(t -> l) - 1, tl -> r, tr);
		pull(tl);
	} else {
		tr = t;
		push(tr);
		split(t -> l, k, tl, tr -> l);
		pull(tr);
	}
}
void insert(Treap* &t, int val) {
	t = merge(t, new Treap(val));
}
void solve() {
	int n, m;
	cin >> n >> m;
	Treap* t = NULL;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		insert(t, x);
	}
	debug(sum(t));
	for(int i = 0; i < m; ++i) {
		int op;
		cin >> op;
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		Treap *tl = NULL, *tr = NULL;
		split(t, l - 1, tl, t);
		split(t, len, t, tr);
		debug(sz(t));
		if(op == 1) reverse(t);
		else cout << sum(t) << '\n';	
		t = merge(tl, merge(t, tr));
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

