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
	char c;
	int poscnt = 1, negcnt = 0;
	vector<char> op;
	while(cin >> c) {
		if(c == '=') break;	
		if(c == '+') op.push_back(c);	
		else if(c == '-') op.push_back(c);	
	}
	int n;
	cin >> n;
	ll l = poscnt - negcnt * n;
	ll r = poscnt * n - negcnt;
	if(n < l || n > r) {
		cout << "Impossible\n";
		return;
	}
	cout << "Possible\n";
	vector<int> pos, neg;
	for(int i = 0; i < poscnt; ++i) {
		pos.push_back(n);
	}
	for(int i = 0; i < negcnt; ++i) {
		neg.push_back(1);
	}
	int cur = poscnt * n - negcnt, idx = 0;
	while(cur > n && idx < poscnt) {
		if(cur - n + 1 >= n) {
			pos[idx] -= n - 1;
			cur -= n - 1;
		} else {
			pos[idx] -= cur - n;
			cur = n;
		}
		++idx;
	}
	idx = 0;
	while(cur > n && idx < negcnt) {
		if(cur - n + 1 >= n) {
			neg[idx] += n - 1;
			cur -= n - 1;
		} else {
			neg[idx] -= cur - n;
			cur = n;
		}
		++idx;
	}
	int posidx = 0, negidx = 0;
	cout << pos[posidx++];
	for(auto p : op) {
		cout << ' ' << p << ' ';
		if(p == '+') cout << pos[posidx++];
		else cout << neg[negidx++];
	}
	cout << " = " << n << '\n';
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

