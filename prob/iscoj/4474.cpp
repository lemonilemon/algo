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
const int MAXN = 3e5 + 5, MAXA = 3e5 + 5, MAGIC = 32;
int a[MAXN];
vector<int> pos[MAXA];
void solve() {
	auto seed = chrono::steady_clock::now().time_since_epoch().count();
	mt19937 rng(seed);
	int N, Q;
	cin >> N >> Q;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back(i);
	}	
	for(int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		bool flag = 0;
		for(int j = 0; j < MAGIC; ++j) {
			int p = uniform_int_distribution<int>(l, r)(rng);
			int num = a[p];
			int cnt = 0;
			cnt += upper_bound(pos[num].begin(), pos[num].end(), r) - lower_bound(pos[num].begin(), pos[num].end(), l);
			if((cnt << 1) > (r - l + 1)) {
				cout << num << '\n';
				flag = 1;
				break;
			}
		}
		if(!flag) cout << "0\n";
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

