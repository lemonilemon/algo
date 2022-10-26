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
const int MAXN = 2e5 + 5, MAXQ = 2e5 + 5;
int seg[MAXN << 2];
int x[MAXN];
int ans[MAXQ];
vector<pair<int, int> > evs[MAXN]; // ed -> (st, ord)
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void modify(int q, int val, int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int query(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for(int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		evs[r].push_back(make_pair(l, i));
	}
	map<int, int> mp;	
	for(int r = 1; r <= n; ++r) {
		int val = x[r];
		if(mp.count(val)) modify(mp[val], -1);	
		mp[val] = r;	
		modify(mp[val], 1);
		for(auto [l, ord] : evs[r]) {
			ans[ord] = query(l, r);
			debug(l), debug(r), debug(ans[ord]);
		}
	}
	for(int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
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

