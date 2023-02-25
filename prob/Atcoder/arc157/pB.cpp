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

void solve() {
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	int ycnt = 0;
	for(int i = 0; i < N; ++i) {
		if(s[i] == 'Y') ++ycnt;	
	}
	if(ycnt + K == N) {
		cout << N - 1 << '\n';
		return;
	}
	if(ycnt + K > N) {
		for(int i = 0; i < N; ++i) {
			if(s[i] == 'Y') s[i] = 'X';
			else s[i] = 'Y';
		}
		ycnt = N - ycnt;
		K = N - K;
	}
	if(!ycnt) {
		cout << max(K - 1, 0) << '\n';
		return;
	}
	int lasty = -1;
	priority_queue<int, vector<int>, greater<> > pq;
	for(int i = 0; i < N; ++i) {
		if(s[i] == 'Y') {
			if(~lasty) pq.push(i - lasty - 1);	
			lasty = i;
		}
	}
	int ans = 0;
	while(!pq.empty() && K >= pq.top()) {
		int dis = pq.top();
		pq.pop();
		ans += dis + 1;	
		K -= dis;
	}
	ans += K;
	cout << ans << '\n';
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

