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

const int MAXN = 1e5 + 5;
struct Student {
	ll s, a, b;
	bool operator < (const Student& that) const {
		return b < that.b;
	}
} stu[MAXN];
ll N, C;
ll f(ll k) {
	ll ret = 0;
	ll l = 2 * N * (k - 1) + 1, r = 2 * N * k; //[]
	ll sum = 0;
	for(int i = 1; i <= N; ++i) {
		sum += stu[i].s;
	}
	for(int i = 1; i <= N; ++i) {
		auto [s, a, b] = stu[i];
		if(s < k) {
			sum += k - s;	
			ret += a * (k - s);
		}
	}
	if(sum < l) {
		ll mn = stu[1].a;
		for(int i = 2; i <= N; ++i) {
			mn = min(mn, stu[i].a);
		}
		ret += (l - sum) * mn;
		return ret;
	}
	if(sum > r) {
		for(int i = 1; i <= N; ++i) {
			auto [s, a, b] = stu[i];
			ll num = max(s - k, 0ll);
			if(num > sum - r) {
				ret += (sum - r) * b;
				return ret;
			}
			sum -= num;
			ret += num * b;
		}
	}
	return ret;
}

void solve() {
	cin >> N >> C;
	for(int i = 1; i <= N; ++i) {
		cin >> stu[i].s;
	}
	for(int i = 1; i <= N; ++i) {
		cin >> stu[i].a;
	}
	for(int i = 1; i <= N; ++i) {
		cin >> stu[i].b;
	}
	sort(stu + 1, stu + N + 1);
	ll l = 0, r = C;
	while(r - l > 2) {
		ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
		debug(m1), debug(m2);
		if(f(m1) < f(m2)) r = m2;
		else l = m1;	
	}
	ll mid = (l + r) >> 1;
	cout << min({f(l), f(mid), f(r)}) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

