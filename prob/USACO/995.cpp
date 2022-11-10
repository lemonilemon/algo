#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int MAXP = 4e5 + 5, INF = 2e9 + 7;
ll BIT[MAXP << 1];
void modify(int k, ll val) {
	for(; k < (MAXP << 1); k += k & -k) BIT[k] = min(BIT[k], val);
}
ll query(int k) {
	ll ret = INF;
	for(; k > 0; k -= k & -k) ret = min(ret, BIT[k]);
	return ret;
}
struct Event {
	int type;
	int y;
	ll arg1, arg2; 
	Event(): type(0), y(0), arg1(0), arg2(0) {}
	Event(int _type, int _y, ll _arg1, ll _arg2): type(_type), y(_y), arg1(_arg1), arg2(_arg2) {}
	/* type 1:
	 * arg1 : to_x
	 * arg2 : to_y
	 * type 2:
	 * arg1 : cost
	 * arg2 : -1
	 */
	bool operator < (const Event& that) const {
		return type == that.type? y < that.y : type > that.type;
	}
	bool operator > (const Event& that) const {
		return type == that.type? y > that.y : type < that.type;
	}
};
vector<int> vals;
priority_queue<Event, vector<Event>, greater<> > evs[MAXP];
int discrete(ll x) {
	return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}
ll restore(int x) {
	return vals[x - 1];
}
int x[2][MAXP], y[2][MAXP];
void solve() {
	int n, p;
	cin >> n >> p;
	vals.push_back(0);
	vals.push_back(n);
	for(int i = 1; i <= p; ++i) {
		for(int j = 0; j < 2; ++j) {
			cin >> x[j][i] >> y[j][i];
			vals.push_back(x[j][i]);
			vals.push_back(y[j][i]);
		}
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for(int i = 1; i <= p; ++i) {
		for(int j = 0; j < 2; ++j) {
			x[j][i] = discrete(x[j][i]);
			y[j][i] = discrete(y[j][i]);
		}
		evs[x[0][i]].push({1, y[0][i], x[1][i], y[1][i]});
	}
	for(int dx = 1; dx <= (int)vals.size(); ++dx) {
		while(!evs[dx].empty()) {
			auto [type, dy, arg1, arg2] = evs[dx].top();
			evs[dx].pop();
			debug(type), debug(restore(dx)), debug(restore(dy));
			if(type == 1) {
				ll step = query(dy) + restore(dx) + restore(dy);
				ll cost = step - restore(arg1) - restore(arg2);
				evs[arg1].push(Event(2, (int)arg2, cost, -1));
			} else debug(arg1), modify(dy, arg1);	
		}
	}
	cout << query(discrete(n)) + (n << 1) << '\n';
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

