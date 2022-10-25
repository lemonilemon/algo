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
const int MAXN = 2e5 + 5, INF = 1e9 + 7;
int h[MAXN];
int seg[MAXN << 2];
void pull(int v) {
	seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
void build(int l, int r, int v) {
	if(l == r) {
		debug(l), debug(r), debug(v);
		seg[v] = h[l];
		debug(seg[v]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
	debug(l), debug(r), debug(v);
	debug(seg[v]);
}
void modify(int q, int val, int l, int r, int v) {
	if(l == r) {
		seg[v] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int lb(int x, int l, int r, int v) {
	if(seg[v] < x) return INF;
	while(l != r) {
		debug(l), debug(r), debug(v);
		int mid = (l + r) >> 1;
		debug(seg[v << 1]);
		if(seg[v << 1] < x) {
			v = v << 1 | 1;
			l = mid + 1;
		} else{
			v = v << 1;
			r = mid;
		}
	}
	return l;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	build(1, n, 1);
	//debug(lb(4, 1, n, 1));
	for(int i = 1; i <= m; ++i) {
		int r;
		cin >> r;
		int mnpos = lb(r, 1, n, 1);
		if(mnpos == INF) {
			cout << '0' << " \n"[i == m];
			continue;
		}
		h[mnpos] -= r;
		modify(mnpos, h[mnpos], 1, n, 1);
		cout << mnpos << " \n"[i == m];
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

