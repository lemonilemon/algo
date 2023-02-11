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
const int MAXN = 2e5 + 5, INF = 1e9 + 7;
int a[MAXN];
ll presum[MAXN], dp[MAXN];
vector<ll> vals;
int discrete(ll x) {
	return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}
int N;
int BIT[MAXN];
void modify(int k, int val) {
	for(; k < MAXN; k += k & -k) BIT[k] = max(val, BIT[k]);
}
int query(ll k) {
	int ret = -INF;
	for(; k > 0; k -= k & -k) ret = max(BIT[k], ret);
	return ret;
}
void solve() {
	for(int i = 0; i < MAXN; ++i) {
		BIT[i] = -INF;
	}
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		presum[i] = presum[i - 1] + a[i];
		vals.push_back(presum[i]);
	}
	sort(vals.begin(), vals.end());
	for(int i = 1; i <= N; ++i) {	
		debug(i);
		debug(presum[i]);
		presum[i] = discrete(presum[i]);
		debug(presum[i]);
	}
	modify(discrete(0), 0);
	for(int i = 1; i <= N; ++i) {
		debug(i);
		dp[i] = max(dp[i - 1], 1ll * query(presum[i]) + i);
		debug(query(presum[i]));
		debug(dp[i]);
		modify(presum[i], dp[i] - i);
	}
	cout << dp[N] << '\n';
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

