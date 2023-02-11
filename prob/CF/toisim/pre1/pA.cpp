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
const int MAXN = 2e5 + 5;
int p[MAXN], q[MAXN];
bool sp[MAXN], sq[MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> p[i];	
	}
	int x;
	cin >> x;
	for(int i = 1; i <= N; ++i) {
		char ch;
		cin >> ch;
		sp[p[i]] = (ch == '1');
	}
	for(int i = 1; i <= N; ++i) {
		cin >> q[i];
	}
	int y;
	cin >> y;
	for(int i = 1; i <= N; ++i) {
		char ch;
		cin >> ch;
		sq[q[i]] = (ch == '1');
	}
	for(int i = 1; i <= N; ++i) {
		debug(i), debug(sp[i]), debug(sq[i]);
	}
	set<int> curp, curq;
	priority_queue<int, vector<int>, greater<> > pq;
	int pidx = 1, qidx = 1;
	for(; pidx <= x; ++pidx) {
		curp.insert(p[pidx]);
	}
	for(; qidx <= y; ++qidx) {
		if(curp.count(q[qidx])) pq.push(q[qidx]);
		curq.insert(q[qidx]);
	}
	vector<int> ans;
	while(!pq.empty()) {
		int cur = pq.top();
		debug(cur);
		pq.pop();
		if(!sp[cur] && !sq[cur]) {
			cout << "-1\n";
			return;
		}
		ans.push_back(cur);
		if(sp[cur]) {
			curq.erase(cur);
			debug(q[qidx]);
			if(curp.count(q[qidx])) pq.push(q[qidx]);
			curq.insert(q[qidx]);
			++qidx;
		} else {
			curp.erase(cur);
			debug(p[pidx]);
			if(curq.count(p[pidx])) pq.push(p[pidx]);
			curp.insert(p[pidx]);
			++pidx;
		}
	}
	for(auto pf : curp) {
		debug(pf);
		if(!sp[pf]) {
			cout << "-1\n";
			return;
		}
	}
	for(auto qf : curq) {
		debug(qf);
		if(!sq[qf]) {
			cout << "-1\n";
			return;
		}
	}
	cout << (int)ans.size() << '\n';
	for(int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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

