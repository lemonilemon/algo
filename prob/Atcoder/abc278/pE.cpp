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
const int MAXH = 305, MAXW = 305, MAXN = 305;
int A[MAXH][MAXW];
int cnt[MAXN];
int dif;
void add(int val) {
	if(!cnt[val]) ++dif;
	++cnt[val];
}
void del(int val) {
	--cnt[val];
	if(!cnt[val]) --dif;
}
void solve() {
	int H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			cin >> A[i][j];
			++cnt[A[i][j]];
		}
	}
	for(int i = 1; i <= N; ++i) {
		dif += (bool)cnt[i];
	}
	for(int k = 0; k <= H - h; ++k) {
		for(int i = k + 1; i <= k + h; ++i) {
			for(int j = 1; j <= w; ++j) {
				del(A[i][j]);
			}
		}
		for(int i = 1; i <= N; ++i) {
			debug(i);
			debug(cnt[i]);
		}
		cout << dif;
		for(int r = w + 1; r <= W; ++r) {
			int l = r - w + 1;
			for(int i = k + 1; i <= k + h; ++i) {
				add(A[i][l - 1]);
				del(A[i][r]);
			}
			debug(l);
			debug(r);
			for(int i = 1; i <= N; ++i) {
				debug(i);
				debug(cnt[i]);
			}
			cout << ' ' << dif;
		}
		cout << '\n';
		for(int i = k + 1; i <= k + h; ++i) {
			for(int j = W - w + 1; j <= W; ++j) {
				add(A[i][j]);
			}
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

