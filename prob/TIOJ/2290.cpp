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
const int MAXA = 1e7 + 5;
bool isprime[MAXA];
int leastprime[MAXA], diff[MAXA], cnt[MAXA];
vector<int> prime;
void init() {
	for(int i = 2; i < MAXA; ++i) {
		isprime[i] = 1;
	}
	for(int i = 2; i < MAXA; ++i) {
		if(isprime[i]) prime.push_back(i);
		for(auto p : prime) {
			if(i * p >= MAXA) break;
			isprime[i * p] = 0;
			leastprime[i * p] = p;
			if(p % i) break;
		}
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++diff[1];
		--diff[a + 1];
	}
	for(int i = 0; i < m; ++i) {
		int b;
		cin >> b;
		--diff[1];
		++diff[b + 1];
	}
	for(int i = 1; i < MAXA; ++i) {
		cnt[i] = cnt[i - 1] + diff[i];
	}
	for(int i = MAXA - 1; i > 1; --i) {
		int p = leastprime[i];
		if(isprime[i]) continue;
		cnt[p] += cnt[i];
		cnt[i / p] += cnt[i];
		cnt[i] = 0;
	}
	cnt[1] = 0;
	for(int i = 1; i < MAXA; ++i) {
		if(cnt[i] < 0) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	return;
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	init();
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

