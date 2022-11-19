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
const int MAXQ = 2e5 + 5;
struct Query {
	int T, A, B;
} quest[MAXQ];
set<int> s[MAXQ << 1];
vector<int> vals;
int discrete(int k) {
	return lower_bound(vals.begin(), vals.end(), k) - vals.begin();
}
void solve() {
	int N, Q;
	cin >> N >> Q;
	for(int i = 0; i < Q; ++i) {
		auto& [T, A, B] = quest[i];
		cin >> T >> A >> B;
		vals.push_back(A);
		vals.push_back(B);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for(int i = 0; i < Q; ++i) {
		auto& [T, A, B] = quest[i];
		A = discrete(A);
		B = discrete(B);
		switch(T) {
			case 1:
				s[A].insert(B);
				break;
			case 2:
				s[A].erase(B);
				break;
			case 3:
				if(s[A].count(B) && s[B].count(A)) cout << "Yes\n";
				else cout << "No\n";
				break;
		}
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

