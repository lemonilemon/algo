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
const int MAXN = 50005;
bool isprime[MAXN];
int mu[MAXN];
ll premu[MAXN];
vector<int> prime;
void init() {
	for(int i = 2; i < MAXN; ++i) {
		isprime[i] = 1;
	}
	mu[1] = 1;
	for(int i = 2; i < MAXN; ++i) {
		if(isprime[i]) {
			prime.emplace_back(i);
			mu[i] = -1;
		}
		for(auto p : prime) {
			if(1ll * i * p >= MAXN) break;
			isprime[i * p] = 0;
			mu[i * p] = mu[i] * mu[p];
			if(!(i % p)) {
				mu[i * p] = 0;
				break;
			}
		}
	}
	for(int i = 1; i < MAXN; ++i) {
		premu[i] = mu[i] + premu[i - 1];
	}
}
void solve() {
	int a, b, d;
	while(cin >> a >> b >> d) {
		if(!a && !b && !d) break;
		a /= d;
		b /= d;
		ll ans = 0;
		for(int i = 1; i <= min(a, b); ++i) {
			int nxti = min(a/(a/i), b/(b/i));
			ans += (premu[nxti] - premu[i - 1]) * (a / i) * (b / i);
			i = nxti;
		}
		cout << ans << '\n';
	}	
}

int main() {
	setIO();
	init();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

