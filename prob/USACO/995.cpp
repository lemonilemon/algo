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
void setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return;
	freopen((file + ".in").c_str(), "r", stdin); 
	freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXP = 2e5 + 5;
const ll INF = 1e18 + 7;
struct Spring {
	int x1, y1, x2, y2;
} s[MAXP];
ll seg[MAXP << 4];
void pull(int v) {
	seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
void build(int l, int r, int v) {
	if(l == r) {
		seg[v] = INF;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
void modify(int q, ll val, int l, int r, int v) {
	if(l == r) {
		seg[v] = min(seg[v], val);
		return;
	}
	int mid = (l + r) >> 1;
	if(q <= mid) modify(q, val, l, mid, v << 1);
	else modify(q, val, mid + 1, r, v << 1 | 1);
	pull(v);
}
ll query(int ql, int qr, int l, int r, int v) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return min(query(ql, mid, l, mid, v << 1), query(mid + 1, qr, mid + 1, r, v << 1 | 1));
}
vector<int> vals;
int discrete(int k) {
	return lower_bound(vals.begin(), vals.end(), k) - vals.begin() + 1;
}
int trans(int k) {
	return vals[k - 1];
}
struct Event {
	int y;
	int type;
	// type 1
	ll cost;
	// type 2
	int tox, toy;
	bool operator < (const Event& that) const {
		return y == that.y? type < that.type : y < that.y;
	}
	bool operator > (const Event& that) const {
		return y == that.y? type > that.type : y > that.y;
	}
};
priority_queue<Event, vector<Event>, greater<> > event[MAXP << 2];
void solve() {
	int N, P;
	cin >> N >> P;
	vals.push_back(0);
	vals.push_back(N);
	for(int i = 0; i < P; ++i) {
		auto& [x1, y1, x2, y2] = s[i];
		cin >> x1 >> y1 >> x2 >> y2;
		vals.push_back(x1);
		vals.push_back(y1);
		vals.push_back(y1);
		vals.push_back(y2);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for(int i = 0; i < P; ++i) {
		auto& [x1, y1, x2, y2] = s[i];
		x1 = discrete(x1);
		y1 = discrete(y1);
		x2 = discrete(x2);
		y2 = discrete(y2);
	}
	for(int i = 0; i < P; ++i) {
		auto [x1, y1, x2, y2] = s[i];
		Event temp;
		temp.y = y1;
		temp.type = 2;
		temp.tox = x2;
		temp.toy = y2;
		event[x1].push(temp);
	}
	int mx = discrete(N);
	build(1, mx, 1);
	modify(1, 0, 1, mx, 1);
	for(int x = 0; x <= mx; ++x) {
		while(!event[x].empty()) {
			auto e = event[x].top();
			event[x].pop();
			int y = e.y;
			if(e.type == 1) modify(y, e.cost, 1, mx, 1);
			else {
				ll cost = query(1, y, 1, mx, 1) + trans(x) + trans(y);
				debug(trans(x)), debug(trans(y));
				debug(cost);
				Event temp;
				temp.y = e.toy;
				temp.type = 1;
				temp.cost = cost - trans(e.tox) - trans(e.toy);
				event[e.tox].push(temp);
			}
		}
	}
	ll cost = query(1, mx, 1, mx, 1) + (N << 1);
	cout << cost << '\n';
}

int main() {
	setIO("boards");
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

