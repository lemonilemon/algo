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
const int MAXN = 8e4 + 5, MOD = 998244353;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int msub(int a, int b) {
	return mabs(a - b);
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
int fastpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = mmul(ret, a);
		a = mmul(a, a);
		b >>= 1;
	}
	return ret;
}
int a[MAXN], d[MAXN], deg[MAXN], inv[MAXN];
int modinv(int a) {
	return inv[a];
}
struct DSU {
	int rt[MAXN], rk[MAXN], val[MAXN], ans;
	DSU(): ans(0) {
		for(int i = 1; i < MAXN; ++i) {
			rt[i] = i;
			rk[i] = 1;
			val[i] = 0;
		}
	}
	int find(int k) {
		return k == rt[k]? k : rt[k] = find(rt[k]);
	}
	bool setunion(int k1, int k2) {
		int u1 = find(k1), u2 = find(k2);
		if(u1 == u2) ans = msub(ans, val[u1]);
		else ans = msub(ans, madd(val[u1], val[u2]));
		if(deg[k1]) val[u1] = mmul(val[u1], mmul(modinv(deg[k1]), deg[k1] + 1));
		else val[u1] = 1;
		++deg[k1];
		if(deg[k2]) val[u2] = mmul(val[u2], mmul(modinv(deg[k2]), deg[k2] + 1));
		else val[u2] = 1;
		++deg[k2];
		if(u1 == u2) {
			debug(val[u1]);
			ans = madd(ans, val[u1]);
			return 0;
		}
		if(rk[u2] > rk[u1]) swap(u1, u2);
		rt[u2] = u1;
		rk[u1] += rk[u2];
		val[u1] = mmul(val[u1], val[u2]);
		ans = madd(ans, val[u1]);
		debug(val[u1]);
		return 1;
	}
} dsu;
void init() {
	for(int i = 0; i < MAXN; ++i) {
		inv[i] = fastpow(i, MOD - 2);
	}
}
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= N; ++i) {
		cin >> d[i];
	}
	unordered_map<int, int> mp;
	vector<int> ans;
	for(int i = N; i > 0; --i) {
		int cur = d[i];
		for(int j = 0; j < 20; ++j) {
			int v = a[cur] ^ (1 << j);
			if(mp.count(v)) {
				debug(cur), debug(mp[v]);
				dsu.setunion(cur, mp[v]);
			}
		}
		for(int j = 0; j < 20; ++j) {
			for(int k = j + 1; k < 20; ++k) {
				int v = a[cur] ^ (1 << j) ^ (1 << k);
				if(mp.count(v)) {
					debug(cur), debug(mp[v]);
					dsu.setunion(cur, mp[v]);
				}
			}
		}
		ans.emplace_back(dsu.ans);
		mp[a[cur]] = cur;
	}
	for(int i = N - 1; i >= 0; --i) {
		cout << ans[i] << '\n'; 
	}
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

