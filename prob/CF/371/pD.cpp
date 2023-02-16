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
const int MAXN = 2e5 + 5;
struct DSU {
	int rt[MAXN], rk[MAXN];
	DSU() {
		for(int i = 1; i < MAXN; ++i) {
			rt[i] = i;
			rk[i] = 1;
		}
	}
	int find(int k) {
		return k == rt[k]? k : rt[k] = find(rt[k]);
	}
	bool setunion(int k1, int k2) {
		int u1 = find(k1), u2 = find(k2);
		if(u1 == u2) return 0;
		rt[u1] = u2;
		return 1;
	}
} dsu;
int a[MAXN], cur[MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		cur[i] = 0;
	}
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i) {
		int op;
		cin >> op;
		if(op == 1) {
			int p, x;
			cin >> p >> x;
			p = dsu.find(p);
			while(x > 0 && p <= N) {
				//debug(p), debug(x);
				if(x >= a[p] - cur[p]) {
					x -= a[p] - cur[p];
					cur[p] = a[p];
					dsu.setunion(p, p + 1);
					p = dsu.find(p);
				} else {
					cur[p] += x;
					break;
				}
			}
		} else {
			int k;
			cin >> k;
			cout << cur[k] << '\n';
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

