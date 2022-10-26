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
	int sz, pri, val;
	Treap *l, *r;
	Treap(int _val): sz(1), pri(rand()), val(_val), l(NULL), r(NULL) {}
};
int sz(Treap* t) {
	return t? t -> sz : 0;
}
void pull(Treap* t) {
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
}
Treap* merge(Treap* tl, Treap* tr) {
	if(!tl || !tr) return tl? tl : tr;
	if(tl -> pri > tr -> pri) {
		tl -> r = merge(tl -> r, tr);
		pull(tl);
		return tl;
	} else{
		tr -> l = merge(tl, tr -> l);
		pull(tr);
		return tr;
	}
}
void split(Treap* t, int k, Treap* &tl, Treap* &tr) {
	if(!t) {
		tl = tr = NULL;
		return;
	}
	if(sz(t -> l) + 1 <= k) {
		tl = t;
		split(t -> r, k - sz(t -> l) - 1, tl -> r, tr);
		pull(tl);
	} else {
		tr = t;
		split(t -> l, k, tl, tr -> l);
		pull(tr);
	}
}
Treap* insert(Treap* t, int val) {
	return merge(t, new Treap(val));
}
void solve() {
	int n;
	cin >> n;
	Treap* t = NULL;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		t = insert(t, x);	
	}
	for(int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		Treap *tl = NULL, *tr = NULL;
		split(t, p - 1, tl, t);
		split(t, 1, t, tr);
		cout << t -> val << " \n"[i == n - 1];
		t = merge(tl, tr);
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

