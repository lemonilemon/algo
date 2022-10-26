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
const int MAXN = 2e5 + 5;
int p[MAXN];
int seg[MAXN << 4];
vector<int> vals;
void pull(int v) {
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l = 1, int r = (MAXN << 2), int v = 1) {
	if(l == r) {
		seg[v] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int q, int val, int l = 1, int r = (MAXN << 2), int v = 1) {
	if(l == r) {
		seg[v] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
int query(int ql, int qr, int l = 1, int r = (MAXN << 2), int v = 1) {
	if(ql == l && qr == r) return seg[v];	
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
int discrete(int k) {
	return lower_bound(vals.begin(), vals.end(), k) - vals.begin() + 1;
}
struct Event {
	int type;
	int arg1, arg2;
	Event(int _type, int _arg1, int _arg2): type(_type), arg1(_arg1), arg2(_arg2) {}
};
void solve() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		vals.push_back(p[i]);
	}
	vector<Event> evs;
	for(int i = 0; i < q; ++i) {
		char op;
		int arg1, arg2;
		cin >> op >> arg1 >> arg2;
		int type = (op == '!' ? 1 : 2);
		if(type == 2) vals.push_back(arg1);
		vals.push_back(arg2);
		evs.push_back(Event(type, arg1, arg2)); 
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	orange(vals.begin(), vals.end());
	for(int i = 1; i <= n; ++i) {
		p[i] = discrete(p[i]);	
		debug(i), debug(p[i]);
	}
	for(auto& [type, arg1, arg2] : evs) {
		if(type == 2) arg1 = discrete(arg1);
		arg2 = discrete(arg2);
		debug(type), debug(arg1), debug(arg2);
	}
	build();
	for(int i = 1; i <= n; ++i) {
		modify(p[i], 1);
	}
	for(auto& [type, arg1, arg2] : evs) {
		if(type == 1) {
			modify(p[arg1], -1);
			p[arg1] = arg2;
			modify(p[arg1], 1);
		} else cout << query(arg1, arg2) << '\n';
	}
	return;
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

