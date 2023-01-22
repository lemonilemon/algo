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
int a[MAXN];
ll sum;
int N, M, K;
multiset<int> L, R;
void add(int k) {
	if((int)L.size() < K) {
		sum += k;
		L.insert(k);
		return;
	}
	if(k < *prev(L.end())) {
		auto l = prev(L.end());
		int lval = *l;
		L.erase(l);
		sum -= lval;
		sum += k;
		L.insert(k);
		R.insert(lval);
	} else R.insert(k);
}
void remove(int k) {
	if(R.find(k) != R.end()) {
		R.erase(R.find(k));
		return;
	}
	L.erase(L.find(k));
	sum -= k;
	auto r = R.begin();
	int rval = *r; 
	R.erase(r);
	sum += rval;
	L.insert(rval);
}
void solve() {
	cin >> N >> M >> K;
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < M; ++i) {
		add(a[i]);	
		debug(i), debug(sum);
	}
	cout << sum;
	for(int i = M; i < N; ++i) {
		remove(a[i - M]);
		add(a[i]);
		cout << ' ' << sum;
	}
	cout << '\n';
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

