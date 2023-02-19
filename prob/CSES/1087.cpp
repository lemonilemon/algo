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
int t(char ch) {
	if(ch == 'A') return 0;
	if(ch == 'T') return 1;
	if(ch == 'C') return 2;
	if(ch == 'G') return 3;
	return -1;
}
char rt(int k) {
	switch(k) {
		case 0:
			return 'A';
		case 1:
			return 'T';
		case 2:
			return 'C';
		case 3:
			return 'G';
		default:
			return '\0';
	}
}
bool exist[4];
int existcnt;
void solve() {
	string s;
	cin >> s;
	string ans;
	for(auto ch : s) {
		if(!exist[t(ch)]) {
			++existcnt;
			exist[t(ch)] = 1;
			if(existcnt == 4) {
				ans += ch;
				for(int i = 0; i < 4; ++i) {
					exist[i] = 0;
				}
				existcnt = 0;
			}
		}
	}
	for(int i = 0; i < 4; ++i) {
		if(!exist[i]) {
			ans += rt(i);
			break;
		}
	}
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

