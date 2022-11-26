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
const int MAXN = 3e5 + 5, MAXQ = 3e5 + 5;
int in[MAXN + MAXQ], root[MAXN];
struct DSU {
	int rt[MAXN + MAXQ], rk[MAXN + MAXQ];
	DSU() {
		for(int i = 0; i < MAXN + MAXQ; ++i) {
			rk[i] = 1;
			rt[i] = i;
		}
	}
	int findroot(int k) {
		return k == rt[k]? k : rt[k] = findroot(rt[k]);
	}
	void setunion(int k1, int k2) {
		k1 = findroot(k1), k2 = findroot(k2);
		if(k1 == k2) return;
		if(rk[k1] > rk[k2]) {
			rk[k1] += rk[k2];
			rt[k2] = k1;
		} else {
			rk[k2] += rk[k1];
			rt[k1] = k2;
		}
	}
} dsu;
void putroot(int k, int box) {
	if(!root[box]) {
		root[box] = k;
		in[root[box]] = box;
	} else {
		dsu.setunion(k, root[box]);
		root[box] = k = dsu.findroot(k);
		in[root[box]] = box;
	}
}
int check(int k) {
	int rt = dsu.findroot(k);
	return in[rt];
}
void solve() {
	int N, Q;
	cin >> N >> Q;
	for(int i = 1; i <= N; ++i) {
		in[i] = i;
		root[i] = i;
	}
	int cnt = N;
	for(int i = 0; i < Q; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int x, y;
			cin >> x >> y;
			if(!root[y]) continue;
			putroot(root[y], x);
			root[y] = 0;
		} else if(op == 2) {
			int x;
			cin >> x;
			putroot(++cnt, x);
		} else {
			int x;
			cin >> x;
			cout << check(x) << '\n';
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

