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
	int key, pri;
	ll val, sum;
	Treap *l, *r;
	Treap(int _key, ll _val): key(_key), pri(rand()), val(_val), sum(_val), l(NULL), r(NULL) {}
};
ll Sum(Treap* t) {
	return t? t -> sum : 0;
}
void pull(Treap *t) {
	t -> sum = t -> val + Sum(t -> l) + Sum(t -> r);
}
void split(Treap *t, int k, Treap* &tl, Treap* &tr) {
	if(!t) {
		tl = tr = NULL;
		return;
	}
	if(t -> key <= k) {
		tl = t;
		split(t -> r, k, tl -> r, tr);
		pull(tl);
	} else {
		tr = t;
		split(t -> l, k, tl, tr -> l);
		pull(tr);
	}
}
Treap* merge(Treap* tl, Treap* tr) {
	if(!tl || !tr) return tl? tl : tr;
	if(tl -> pri > tr -> pri) {
		tl -> r = merge(tl -> r, tr);
		pull(tl);
		return tl;
	} else {
		tr -> l = merge(tl, tr -> l);
		pull(tr);
		return tr;
	}
}
void solve() {
	int n, q;
	cin >> n >> q;
	Treap* t = NULL;
	for(int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		t = merge(t, new Treap(i, x));
	}
	for(int i = 1; i <= q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int k;
			ll u;
			cin >> k >> u;
			Treap *tl, *tr;
			split(t, k - 1, tl, t);
			split(t, k, t, tr);
			t -> val = t -> sum = u;
			t = merge(tl, merge(t, tr));
		} else {
			int l, r;
			cin >> l >> r;
			Treap *tl, *tr;
			split(t, l - 1, tl, t);
			split(t, r, t, tr);
			cout << Sum(t) << '\n';
			t = merge(tl, merge(t, tr));
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

