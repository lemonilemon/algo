#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
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
	char val;
	bool reverse;
	Treap *tl, *tr;
	Treap(char _val): sz(1), pri(rand()), val(_val), reverse(0), tl(NULL), tr(NULL) {}
};
int sz(Treap* t) {
	return t? t -> sz : 0;
}
void reverse(Treap* t) {
	t -> reverse = !t -> reverse;
	swap(t -> tl, t -> tr);	
}
void push(Treap* t) {
	if(t -> reverse) {
		if(t -> tl) reverse(t -> tl);
		if(t -> tr) reverse(t -> tr);
		t -> reverse = 0;
	}
}
void pull(Treap* t) {
	t -> sz = 1 + sz(t -> tl) + sz(t -> tr);
}
Treap* merge(Treap* tl, Treap* tr) {
	if(!tl || !tr) return tl? tl : tr;
	if(tl -> pri > tr -> pri) {
		push(tl);
		tl -> tr = merge(tl -> tr, tr);
		pull(tl);
		return tl;
	} else {
		push(tr);
		tr -> tl = merge(tl, tr -> tl);
		pull(tr);
		return tr;
	}
}
void split(Treap* t, int k, Treap* &tl, Treap* &tr) {
	if(!t) {
		tl = tr = NULL;
		return;
	}
	if(sz(t -> tl) + 1 <= k) {
		tl = t;
		push(tl);
		split(t -> tr, k - sz(t -> tl) - 1, tl -> tr, tr);
		pull(tl);
	} else {
		tr = t;
		push(tr);
		split(t -> tl, k, tl, tr -> tl);
		pull(tr);
	}
}
void insert(Treap* &t, int val) {
	t = merge(t, new Treap(val));
}
void print(Treap* t) {
	push(t);
	if(t -> tl) print(t -> tl);
	cout << t -> val;
	if(t -> tr) print(t -> tr);
}
void solve() {
	int n, m;
	cin >> n >> m;
	Treap *t = NULL;
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		insert(t, ch);
	}
	for(int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		int len = (r - l) + 1;
		Treap *tl = NULL, *tr = NULL;
		split(t, l - 1, tl, t);
		split(t, len, t, tr);
		reverse(t);
		t = merge(tl, merge(t, tr));
	}
	print(t);
	cout << '\n';
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

