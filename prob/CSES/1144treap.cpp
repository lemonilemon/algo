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
	int key, pri;
	int sz;
	Treap *l, *r;
	Treap(int _key): key(_key), pri(rand()), sz(1), l(NULL), r(NULL) {}
};
int sz(Treap* t) {
	return t? t -> sz : 0;
}
void pull(Treap *t) {
	t -> sz = 1 + sz(t -> l) + sz(t -> r);
}
void merge(Treap* t, Treap* tl, Treap* tr) {
	if(!tl || !tr) {
		t = (tl? tl : tr);
		return;
	}
	if(tl -> pri > tr -> pri) {
		t = tl;
		merge(t -> r, tl -> r, tr);
	} else {
		t = tr;
		merge(t -> l, tl, tr -> l);
	} 
	pull(t);
}
void split(Treap* t, int k, Treap* &tl, Treap* &tr) {
	if(!t) {
		tl = tr = NULL;
		return;
	}
	if(t -> key <= k) {
		tl = t;
		split(tl -> r, k, tl -> r, tr);
	} else {
		tr = t;
		split(tr -> l, k, tl, tr -> l);
	}
	pull(t);
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {

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

