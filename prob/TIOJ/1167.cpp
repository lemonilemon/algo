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
const int MAXN = 1e6 + 5;
ll v[MAXN];
int N, k;
void solve() {
	for(int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v, v + N);
	cout << v[N - k] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//int T = 1;
	//cin >> T;
	while(cin >> N >> k) {
		if(!N && !k) break;
		//cout << "Case " << t << ": ";
		solve();
	}
}

